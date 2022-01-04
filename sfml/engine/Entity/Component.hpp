#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace lny {
	typedef sf::Vector2f Vec2;
	/*
		standard Component class, used to derive all other entity components
	*/

	struct Compoment {
		bool isActive = false;
	};

};