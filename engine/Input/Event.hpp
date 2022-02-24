#pragma once
#include <SFML/Graphics.hpp>
#include<string>
namespace lny {
	/*
	* Event struct used for the game engine to communicate inputs to the scene
	*/
	struct Event {
		//wheather or not the event ended
		bool active;
		//magnitude of the event
		lny::Vec2 magnitude;
		//keyboard input constructor
		Event(bool n,lny::Vec2 mag) : active(n), magnitude(mag) {};
		
		
	};

}