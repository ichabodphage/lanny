#pragma once
#include "Component.hpp"
#include <tuple>


template<typename TupleType, typename FunctionType>
void for_each(TupleType&&, FunctionType
	, std::integral_constant<size_t, std::tuple_size<typename std::remove_reference<TupleType>::type >::value>) {}




template<std::size_t I, typename TupleType, typename FunctionType
	, typename = typename std::enable_if<I != std::tuple_size<typename std::remove_reference<TupleType>::type>::value>::type >
	void for_each(TupleType&& t, FunctionType f, std::integral_constant<size_t, I>)
{
	f(std::get<I>(std::forward<TupleType>(t)));
	for_each(std::forward<TupleType>(t), f, std::integral_constant<size_t, I + 1>());
}

template<typename TupleType, typename FunctionType>
void for_each(TupleType&& t, FunctionType f)
{
	for_each(std::forward<TupleType>(t), f, std::integral_constant<size_t, 0>());
}



#define ENTITY_COUNT 3000
namespace lny {
	/*
	* ComponentManager manages the components of entities
	* singleton right now, but will be migrated as an instance variable of EntityManager
	*/
	
	template <class ...types>
	class ComponentManager {
	private:
		//number of entities inside the component manager
		size_t entityCount;
		size_t currentIndex = 0;
		//tuple of all the entity components
		std::tuple<std::vector<types>...> components;
		
		
	public:
		//bool for wheather or not entity is active
		std::vector<bool> active;
		ComponentManager(size_t maxEntities):entityCount(maxEntities){
			//reserve maxEntities amount of space in each vector
			active.reserve(maxEntities);
			for_each(components,
				[maxEntities](auto& x) {
					x.reserve(maxEntities);
				});
		}

		//gets the index of the next unalocated index
		size_t nextEntity() {
			//if the current index is less then entity count, march forward by one
			while (active[currentIndex] == true && currentIndex < entityCount) {
				currentIndex++;
			}
			return currentIndex;
		}
		//adds an entity into the memory pool and returns its index
		size_t addEntity() {
			size_t index = nextEntity();
			active[index] = true;
			return index;

		}
		void destroyEntity(size_t index) {
			active[index] = false;
			for_each(components,
				[index](auto& x) {
					x[index].isActive = false;
				});
			if (index < currentIndex) {
				currentIndex = index;
			}
		}
		//gets a component of an entity
		template<typename T>
		T& getComponent(size_t entityIndex) {
			return std::get<std::vector<T>>(components)[entityIndex];
		}
		
		//sets all entitiy components to inactive
		void deInit() {
			// loop through all entity component vectors
			for_each(components, [](auto& vector) {
				// set isActive on all the components of each vector to false, equivalen
				for (auto& x : vector) {
					x.isActive = false;
				}
			});
			//set isActive to false with allEntities
			for (int i = 0; i < active.size();i++) {
				active[i] = false;
			}
		}

#ifdef ENTITY_COUNT
		static ComponentManager& instance() {
			static ComponentManager pool(ENTITY_COUNT);
			return pool;
		}
#else
		static ComponentManager& instance() {
			static ComponentManager pool(10000);
			return pool;
		}
#endif
	};

}
#define DEFAULT_MANAGER ComponentManager<lny::CompShape, lny::CompTransform,lny::CompBB>