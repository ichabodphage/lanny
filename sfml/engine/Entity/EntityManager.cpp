#include "EntityManager.hpp"

using namespace lny;


Entity EntityManager::addEntity() {
#ifdef COMPONENT_MANAGER
	auto myEntity = COMPONENT_MANAGER::instance().addEntity();
	entities.push_back(Entity(myEntity));
	return myEntity;
#else
	auto myEntity = DEFAULT_MANAGER::instance().addEntity();
	entities.push_back(Entity(myEntity));
	return myEntity;
#endif
}

void EntityManager::deInit() {
#ifdef COMPONENT_MANAGER
	entities.clear();
	COMPONENT_MANAGER::instance().deInit();
#else
	entities.clear();
	DEFAULT_MANAGER::instance().deInit();
#endif
}

void EntityManager::sweepInactive() {
	size_t i = 0;
	while (i < entities.size()) {
		if (!entities[i].isActive()) {
			entities.erase(entities.begin() +i);
			continue;
		}
		i++;

	}
}
