#pragma once
#include <SFML/Graphics.hpp>
#include "Components.hpp"

class Entity{
protected:
	size_t entityCount;	  //total entity count
	bool isActive = true; //is active flag tells the enine if the entity needs to be removed or not
	int name = 0;		  //name id variable, enum used to declare names and their corisponding id's
	
	friend class EntityManager; //EntityManager will be the only class able to access the constructor

public:
	//entity constructor, using id and name
	Entity(size_t c, int n) :entityCount(c), name(n) {};
	//shared ptrs for entity components
	std::shared_ptr<CompPosition> cPosition; 
	std::shared_ptr<CompShape> cShape;

	//setter functions
	void disable() { //isActive setter
		isActive = false;
	}
	//getter functions
	int& getname() { //name getter
		return name;
	}
	size_t& getid() { //entityCount getter
		return entityCount;
	}
};