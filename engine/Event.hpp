#pragma once
#include<string>
namespace lny {
	/*
	* Event struct used for the game engine to communicate inputs to the scene
	*/
	struct Event {
		//event int enum "name"
		int name;
		//activity of the event
		bool active; 
		//magnitude of the event (used for mouse inputs)
		lny::Vec2 magnitude;

		//keyboard input constructor
		Event(int n, bool a) :name(n), active(a) {};
		
		//mouse input constructor
		Event(int n, bool a, lny::Vec2 mag) :name(n), active(a),magnitude(mag) {};
	};

}