#pragma once
#include "../Entity.hpp"
#include "../../Typedefs.hpp"
namespace lny {
	typedef std::vector<lny::Entity> EntityVector;
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
		EntityManager(ComponentMgr* d) :localComponentManager(d) {}
		//array holding entities made by the entity manager
		EntityVector entities;

		//method that inserts an enity into the entity array and returns the same entity
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