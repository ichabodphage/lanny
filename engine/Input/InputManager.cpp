#include "InputManager.hpp"

using namespace lny;

InputManager::InputManager(lny::EntityManager* localManager):entityManager(localManager) {};


void InputManager::listen(enum inputType type, int eventID, std::function<void(lny::Event)>eventFunction) {
	//check if input was allready registered first
	try{
		inputMap.at(eventID * type);
	}catch(std::exception e){
		/*InputHandler holds a lambda, and as such must have its callback function
		* initalized manually. using a contrstructor throws an error
		*/
		lny::InputHandler myHandler;
		myHandler.eventFunction = eventFunction;
		inputMap[eventID*type] = myHandler;	
	}
};
void InputManager::reciveInput(sf::Event myEvent){
	//check if the event is being listened for by the input manager
	try{
		switch(myEvent.type){
			/*keyboard events pass a boolean value for if
			* they key was pressed or released
			*/
			case sf::Event::KeyPressed:
				inputMap.at(myEvent.key.code).eventFunction(lny::Event(true,{0,0}));
				break;
			case sf::Event::KeyReleased:
				inputMap.at(myEvent.key.code).eventFunction(lny::Event(false,{0,0}));
				break;
			/*
			* mouse events pass where the mouse event happened on the window and 			
			* a boolean value for if the event is still active or not
			*/
			case sf::Event::MouseButtonPressed:
				//multiply the input code by lny::Key to prevent map colisions
				inputMap.at(myEvent.mouseButton.button*lny::Mouse)
				.eventFunction(
				lny::Event(true,
				lny::Vec2(myEvent.mouseButton.x,myEvent.mouseButton.y)));
				break;
			case sf::Event::MouseButtonReleased:
				inputMap.at(myEvent.mouseButton.button*lny::Mouse)
				.eventFunction(
				lny::Event(false,
				lny::Vec2(myEvent.mouseButton.x,myEvent.mouseButton.y)));
				break;
			c
		}
		
	}catch(std::exception e){
		
	};
};