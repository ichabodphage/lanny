#include "InputManager.hpp"

using namespace lny;

InputManager::InputManager(lny::EntityManager* localManager):entityManager(localManager) {};


void InputManager::listen(enum inputType type, int eventID, std::function<void(lny::Event)>eventFunction) {
	//check if input was allready registered first
	try{
		inputMap.at(eventID * type);
	}catch(std::exception e){
		lny::InputHandler myHandler;
		myHandler.eventFunction = eventFunction;
		inputMap[eventID*type] = myHandler;	
	}
};
void InputManager::reciveInput(sf::Event myEvent){
	try{
		if (sf::Keyboard::isKeyPressed(myEvent.key.code)){
			inputMap.at(myEvent.key.code).eventFunction(lny::Event(true, { 0,0 }));
	
		}
		else if (sf::Mouse::isButtonPressed(myEvent.mouseButton.button)) {
			inputMap.at(myEvent.mouseButton.button*20).eventFunction(lny::Event(true, lny::Vec2(myEvent.mouseButton.x,myEvent.mouseButton.y)));
		}
	}catch(std::exception e){
		
	};
};