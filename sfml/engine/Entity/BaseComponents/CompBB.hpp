#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Component.hpp"
namespace lny {
	typedef sf::Vector2f Vec2;
	/*
	* bounding box component used for entity colisions
	*/
	struct CompBB : Compoment {
		Vec2 size;
		CompBB(Vec2 p) : size(p){ isActive = true; };
	};
}