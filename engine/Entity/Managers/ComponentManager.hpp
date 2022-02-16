#pragma once
#include "../Component.hpp"
#include "./MemoryPool.hpp"
#include <tuple>
#include <list>

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
	
	template <class ...types>
	class ComponentManager {
	private:
		//tuple of all the entity components
		std::tuple<std::vector<types>...> components;
		//max amount of entities allowed by the component manager
		size_t maxEntitiyCount;
	public:
		//bool for wheather or not entity is active
		MemoryPool<bool> active;
		ComponentManager(size_t maxEntities): active(maxEntities,false), maxEntitiyCount(maxEntities){
			//reserve maxEntities amount of space in each vector
			for_each(components,
				[maxEntities](auto& x) {
					x.reserve(maxEntities);
				});
			
			
		}

		
		
		//adds an entity into the memory pool and returns its index
		size_t addEntity() {
			
			return active.allocate(true);

		}
		void destroyEntity(size_t index) {
			active.deallocate(index);
			for_each(components,
				[index](auto& x) {
					x[index].isActive = false;
				});
			
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
			//reset the active entity memory pool
			active = MemoryPool<bool>(maxEntitiyCount, false);
			
		}
		//resizes the max amount of entities allowed
		void setMaxEntityCount(size_t newMax){
			maxEntitiyCount = newMax;
			//
			active = MemoryPool<bool>(maxEntitiyCount, false);
			//resize all of the component arrays
			for_each(components,
				[newMax](auto& x) {
					x.reserve(newMax);
				});
		}
		//returns the max entity count
		size_t getEntityLimit(){
			return maxEntitiyCount;
		}

	};

}
#define DEFAULT_MANAGER ComponentManager<lny::CompShape, lny::CompTransform,lny::CompBB,lny::CompTexture,lny::CompMovement>