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




namespace lny {
	/*
	* ComponentManager manages the components of entities
	*/
	
	template <class ...types>
	class ComponentManager {
	private:
		//number of entities inside the component manager
		size_t entityCount;
		size_t currentIndex = 0;
		//tuple of all the entity components
		std::tuple<std::vector<types>...> components;
		
		//bool for wheather or not entity is active
		std::vector<bool> active;
	public:
		
		ComponentManager(size_t maxEntities) {
			entityCount = maxEntities;
			active.reserve(maxEntities);

			for_each(components,
				[maxEntities](auto& x) {
					x.reserve(maxEntities);
				});
		}

		//gets the index of the next unalocated index
		size_t nextEntity() {
			size_t old = currentIndex;
			if (currentIndex < entityCount) {
				currentIndex++;
			}
			return old;
		}
		//adds an entity into the memory pool
		size_t addEntity() {
			size_t index = nextEntity();
			active[index] = true;
			return index;

		}

		//gets a component of an entity
		template<typename T>
		T& getComponent(size_t entityIndex) {
			return std::get<std::vector<T>>(components)[entityIndex];
		}
		
		//sets all entitiy components to inactive
		void deInit() {
			for_each(components, [](auto& vector) {
				for (auto& x : vector) {
					x.isActive = false;
				}
			});
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
#define DEFAULT_MANAGER ComponentManager<lny::CompShape, lny::CompTexture, lny::CompTransform>