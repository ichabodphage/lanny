#pragma once
#include <functional>
#include <thread>
#include "../Entity/Entity.hpp"
#include "../Entity/Managers/EntityManager.hpp"
#include "Event.hpp"

namespace lny{
	/*
	* class responsible for processing inputs, uses lambdas to determine
	* behavior
	*/
	//forward declaration
	class LannyEngine;
	class InputHandler{
		public:
			bool active = false;
			//function for the input hanlder to run
			std::function<void(lny::Event)> eventFunction;

			
	};
}