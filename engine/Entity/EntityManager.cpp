#include "EntityManager.hpp"

using namespace lny;


Entity EntityManager::addEntity() {
	auto myEntity = localComponentManager->addEntity();
	entities.push_back(Entity(myEntity, localComponentManager));
	return Entity(myEntity, localComponentManager);
}

void EntityManager::deInit() {
	entities.clear();
	localComponentManager->deInit();

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
