#pragma once
#include <SFML/Graphics.hpp>
#include "BaseComponents/CompShape.hpp"
#include "BaseComponents/CompTransform.hpp"
#include "BaseComponents/CompBB.hpp"
#include "ComponentManager.hpp"

namespace lny {

	/*
	* Entity class, used as a container to hold pointers to entity components in memory.
	* 
	* Entity lacks any means of handling the data within its components as 
	* apart of the engines entity component system archetecture.
	* 
	* handling of entity components is done by the engine and its scenes.
	* 
	* can be derived to add new entity components. its highly discouraged 
	* that mutator methods for such components are implemented in such child classes.
	* 
	*/
	class Entity {
	protected:
		//entity manager
		friend class EntityManager;
		size_t id;	  

	public:
		Entity(size_t i) :id(i) {};
		size_t getid() {
			return id;
		}

		//methods to get components of the specific entity
#ifdef COMPONENT_MANAGER
		template<typename T>
		T& getComponent() {
			return COMPONENT_MANAGER::instance().getComponent<T>(this->id);
		}
		template<typename T>
		bool hasComponent() {
			return COMPONENT_MANAGER::instance().getComponent<T>(this->id).isActive;
			
		}
		
		bool isActive() {
			return COMPONENT_MANAGER::instance().active[this->id];

		}
		void destroy() {
			return COMPONENT_MANAGER::instance().destroyEntity(this->id);

		}
#else 

		template<typename T>
		T& getComponent() {
			return DEFAULT_MANAGER::instance().getComponent<T>(this->id);
		}
		template<typename T>
		bool hasComponent() {
			return DEFAULT_MANAGER::instance().getComponent<T>(this->id).isActive;

		}
		bool isActive() {
			return DEFAULT_MANAGER::instance().active[this->id];
		}
		void destroy() {
			return DEFAULT_MANAGER::instance().destroyEntity(this->id);

		}
#endif // DEFAULT_MANAGER
	};

}