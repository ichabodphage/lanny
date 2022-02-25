#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <queue>
#include "../Entity/Entity.hpp"
#include "../Entity/Managers/EntityManager.hpp"
#include "InputHandler.hpp"
namespace lny{
	/*
	*	class responsible for managing inputs
	*/
	enum inputType {
		Key = 1,
		Mouse = 20,
	};
	class InputManager{
		private:
			//map for all input events
			std::map<int, lny::InputHandler> inputMap;

			//pointer back to entity manager
			lny::EntityManager* entityManager;

		public:
			//constructor using entity manager 
			InputManager(lny::EntityManager* localManager);

			/*
			* method that inserts a new input handler 
			* into the inputEvents map
			*/
			void listen(enum inputType type,int eventID,std::function<void(lny::Event)>eventFunction);

			//recives and runs a specific input
			void reciveInput(sf::Event myEvent);
	};
}