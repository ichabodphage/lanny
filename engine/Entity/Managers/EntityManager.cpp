#include "EntityManager.hpp"

using namespace lny;


Entity EntityManager::addEntity() {
	//add an enity into the component manager
	auto myEntity = localComponentManager->addEntity();
	entities.push_back(Entity(myEntity, localComponentManager));
	//retun an entity struct using the entity ID
	return Entity(myEntity, localComponentManager);
}

void EntityManager::deInit() {
	//clear all the entities and deInit the component manager
	entities.clear();
	localComponentManager->deInit();

}

void EntityManager::sweepInactive() {
	size_t i = 0;
	//go through the entity vector and errase all inactive entities
	while (i < entities.size()) {
		if (!entities[i].isActive()) {
			entities.erase(entities.begin() +i);
			continue;
		}
		i++;

	}
}

void EntityManager::setMaxEntities(size_t newMax){
	localComponentManager->setMaxEntityCount(newMax);
	entities.clear();
}

size_t EntityManager::getEntityLimit(){
	return localComponentManager->getEntityLimit();
}