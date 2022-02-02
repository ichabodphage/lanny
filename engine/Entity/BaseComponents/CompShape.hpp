#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Component.hpp"
namespace lny {
	/*
	* shape entity component used for drawing the entity onto the screen
	*/
	typedef sf::Vector2f Vec2;
	struct CompShape : Compoment {
	public:
		//sf shape used for rendering
		sf::RectangleShape shape;
		//rotation center of the shape
		Vec2 center = { 0,0 };
		CompShape(Vec2 s) :shape(s) {
			isActive = true;
			
		};


	};
}