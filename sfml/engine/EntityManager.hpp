#pragma once
#include "Entity.hpp"
typedef std::vector < std::shared_ptr<lny::Entity>> EntityVector;
typedef std::map<int, EntityVector> EntityMap;
namespace lny {
	class EntityManager {
	public:
		EntityVector entities;
		size_t managerEntityCount = 0;
		EntityMap entityMap;
		EntityManager() {}
		//insert entity method inserts an entity into the entity vector and adds that entity to the entity map
		std::shared_ptr<lny::Entity> insertEntity(int name);

		//gets all entities
		EntityVector& getEntities();

		//gets entities using their name
		EntityVector& getEntities(int name);

		//sweeps dead entities from an entity vector if they are not active
		void sweepInactiveEntities(EntityVector& vect);

		//update function removes all inactive entities from the map and entity vector
		void update();
	};
}