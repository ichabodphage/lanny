#pragma once
#include<string>
namespace lny {
	/*
	* Event struct used for the game engine to communicate inputs to the scene
	*/
	struct Event {
		int name;
		bool active;
		Event(int n, bool a) :name(n), active(a) {};
	};
}