#include "InputManager.hpp"

using namespace lny;

InputManager::InputManager(lny::EntityManager* localManager):entityManager(localManager){};


void InputManager::listen(int eventID,std::function<void(lny::EntityManager*)> eventFunction){
	//check if input was allready registered first
	try{
		inputMap.at(eventID);
	}catch(std::exception e){
		lny::InputHandler myHandler;
		myHandler.eventFunction = eventFunction;
		inputMap[eventID] = myHandler;	
	}
};
void InputManager::reciveInput(int myEvent){
	try{
		inputMap.at(myEvent).eventFunction(entityManager);		
	}catch(std::exception e){
		
	};
};