#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Component.hpp"
#include "../../Renderer/RenderRect.hpp"
namespace lny {
	/*
	* shape entity component used for drawing the entity onto the screen
	*/
	typedef sf::Vector2f Vec2;
	struct CompShape : Compoment {
	public:
		//sf shape used for rendering
		lny::RenderRect shape;
		CompShape(Vec2 size) :shape(size) {
			isActive = true;
			
		};

		CompShape(Vec2 size,lny::Texture* tex) :shape(size,tex) {
			isActive = true;
			
		};

	};
}