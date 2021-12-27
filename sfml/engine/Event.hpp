#pragma once
#include<string>
namespace lny {
	class Event {
	public:
		int name;
		bool active;
		Event(int n, bool a) :name(n), active(a) {};
	};
}