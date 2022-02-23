#pragma once
#include <SFML/Graphics.hpp>
#include <map>

#include "../Entity/Entity.hpp"
#include "../Entity/Managers/EntityManager.hpp"
#include "InputHandler.hpp"

namespace lny{
	/*
	*	class responsible for managing inputs
	*/
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
			void listen(int eventID,std::function<void(lny::EntityManager*)>eventFunction);

			//recives and runs a specific input
			void reciveInput(int myEvent);
	};
}