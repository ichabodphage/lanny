#include "EntityManager.hpp"

using namespace lny;
typedef std::vector < std::shared_ptr<Entity>> EntityVector;
typedef std::map<int, EntityVector> EntityMap;


std::shared_ptr<Entity> EntityManager::insertEntity(int id) {
	//make shared new shared ptr
	auto newEntity = std::make_shared<Entity>(managerEntityCount++, id);
	entities.push_back(newEntity);

	//add entity ptr to map with name as key and return the entity ptr
	entityMap[id].push_back(newEntity);
	return newEntity;
}



EntityVector& EntityManager::getEntities() {
	return entities;
}



EntityVector& EntityManager::getEntities(int name) {
	return entityMap[name];
}



void EntityManager::sweepInactiveEntities(EntityVector& vect) {
	int i = 0;
	//while loop avoids itteator invalidation
	while (i < vect.size()) {
		//remove entity if if it isnt active
		if (!vect[i]->isActive) {
			vect.erase(vect.begin() + i);
			managerEntityCount--;
			continue;
		}
		//if entity is active move to next entity
		i++;
	}
}

void EntityManager::update() {
	//sweep the main entity vector
	sweepInactiveEntities(entities);

	for (auto& key : entityMap) {
		sweepInactiveEntities(key.second);
	}
}