#pragma once
#include <functional>
#include "../Entity/Entity.hpp"
#include "../Entity/Managers/EntityManager.hpp"
#include "Event.hpp"
namespace lny{
	/*
	* class responsible for processing inputs, uses lambdas to determine
	* behavior
	*/
	class InputHandler{
		public:
			//function for the input hanlder to run
			std::function<void(lny::EntityManager*)> eventFunction;

			
	};
}