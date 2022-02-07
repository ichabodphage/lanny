#pragma once
#include <SFML/Graphics.hpp>
#include "CompInclude.hpp"
#include "Managers/ComponentManager.hpp"

namespace lny {

	/*
	* Entity class, used as a container to hold pointers to entity components in memory.
	* 
	* Entity lacks any means of handling the data within its components as 
	* apart of the engines entity component system archetecture.
	* 
	* handling of entity components is done by the entity manager
	* 
	* 
	*/
	class Entity {
	protected:
		//entity manager
		friend class EntityManager;

		//id of the entity
		size_t id;	  

	public:
		//returns the enitity ID
		size_t getid() {
			return id;
		}
		//component manager boilerplate
#ifdef COMPONENT_MANAGER
		typedef COMPONENT_MANAGER ComponentMgr;
#else
		typedef DEFAULT_MANAGER ComponentMgr;
#endif // DEFAULT_MANAGER

		ComponentMgr* localComponentManager;
		Entity(size_t i, ComponentMgr* d) :id(i), localComponentManager(d) {};

		//returns a reference to an entity component
		template<typename T>
		T& getComponent() {
			return localComponentManager->getComponent<T>(this->id);
		}
		//returns the activity status of a specific entity component
		template<typename T>
		bool hasComponent() {
			return localComponentManager->getComponent<T>(this->id).isActive;

		}
		//returns the current activity status of the entity
		bool isActive() {
			return localComponentManager->active.getValue(this->id);
		}
		//sets the entity to inactive
		void destroy() {
			return localComponentManager->destroyEntity(this->id);

		}

	};

}