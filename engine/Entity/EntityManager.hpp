#pragma once
#include "Entity.hpp"
#include "ComponentManager.hpp"
namespace lny {
	typedef std::vector<lny::Entity> EntityVector;
	/*
	* EntityManager class manages insertion, retreval, and removal of entities within a scene.
	* EntityManager is the only class that is allowed to handle anything related to creation and deletion of entities.
	* the class itself does not handle the components of entities, and only manages creation and deletion of the entities themselves
	*/
	class EntityManager {
	public:
#ifdef COMPONENT_MANAGER
		COMPONENT_MANAGER* localComponentManager;
		EntityManager(COMPONENT_MANAGER* d) :localComponentManager(d) {}
		EntityVector entities;
		lny::Entity addEntity();

		void deInit();
		void sweepInactive();
#else
		DEFAULT_MANAGER* localComponentManager;
		EntityManager(DEFAULT_MANAGER* d) :localComponentManager(d) {}
		EntityVector entities;
		lny::Entity addEntity();

		void deInit();
		void sweepInactive();
#endif
	};

}