#pragma once
#include "../Entity.hpp"
#include "../../Typedefs.hpp"
namespace lny {
	/*
	* EntityManager class manages insertion, retreval, 
	* and removal of entities within a scene.
	* EntityManager is the only class that is allowed to handle
	* anything related to creation and deletion of entities.
	* the class itself does not handle the components of entities,
	* and only manages creation and deletion of the entities themselves
	*/

	class EntityManager {
	private:
		//pointer back to the component manager
		ComponentMgr* localComponentManager;

	public:
		//constructor using pointer to the component manager
		EntityManager(ComponentMgr* components) :
		localComponentManager(components) {}

		//array holding entities made by the entity manager
		std::vector<lny::Entity> entities;

		//creates and returns an entity into the EntityManager
		lny::Entity addEntity();

		//clears entities and tells the compoment manager to deconstruct all entity components
		void deInit();
		//removes all inactive entities from the entity array
		void sweepInactive();

		//resets the max entity count
		void setMaxEntities(size_t newMax);

		//returns the entity limit
		size_t getEntityLimit();
	};

}