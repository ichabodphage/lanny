#pragma once
#include <SFML/Graphics.hpp>
#include<string>
namespace lny {
	/*
	* Event struct used for the game engine to communicate inputs to the scene
	*/
	struct Event {
		//event int enum "name"
		int name;

		//keyboard input constructor
		Event(int n) :name(n) {};
		
		
	};

}