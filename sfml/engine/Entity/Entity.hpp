#pragma once
#include <SFML/Graphics.hpp>
#include "Components.hpp"
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
		size_t entityCount;	  //total entity count
		bool isActive = true; //is active flag tells the enine if the entity needs to be removed or not
		int id = 0;			  //id variable, enum used to declare names and their corisponding id's
	public:
		Entity(size_t c, int n) :entityCount(c), id(n) {};
		//position component that holds postion, velocity, and acceleration
		std::shared_ptr<lny::CompPosition> cPosition;
		//shape component that holds the shape that is used to draw the entity
		std::shared_ptr<lny::CompShape> cShape;
		//texture 
		std::shared_ptr<lny::CompTexture> cTexture;

		//disables an entity and flags it for removal by the entity manager
		void disable() {
			isActive = false;
		}
		//gets the integer ID of the entity
		int& getName() { //name getter
			return id;
		}
		//gets the number corisponding to the current amount of entities when the entity was initated
		size_t& getCount() { 
			return entityCount;
		}
	};
}