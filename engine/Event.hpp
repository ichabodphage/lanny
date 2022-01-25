#pragma once
#include<string>
namespace lny {
	/*
	* Event struct used for the game engine to communicate inputs to the scene
	*/
	struct Event {
		int name;
		bool active;
		lny::Vec2 magnitude;
		Event(int n, bool a) :name(n), active(a) {};
		Event(int n, bool a, lny::Vec2 mag) :name(n), active(a),magnitude(mag) {};
	};

}