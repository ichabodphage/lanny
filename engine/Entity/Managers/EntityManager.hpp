#pragma once
#include "../Entity.hpp"
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
	typedef COMPONENT_MANAGER ComponentMgr;
	typedef std::unique_ptr <COMPONENT_MANAGER> ComponentManagerPtr;
#else
	typedef DEFAULT_MANAGER ComponentMgr;
	typedef std::unique_ptr <DEFAULT_MANAGER> ComponentManagerPtr;
#endif // DEFAULT_MANAGER


		ComponentMgr* localComponentManager;
		EntityManager(ComponentMgr* d) :localComponentManager(d) {}
		EntityVector entities;
		lny::Entity addEntity();

		void deInit();
		void sweepInactive();

	};

}