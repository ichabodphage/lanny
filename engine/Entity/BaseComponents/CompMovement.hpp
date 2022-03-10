#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Component.hpp"
#include "../../Renderer/RenderRect.hpp"
namespace lny {
	/*
	* movement entity component used to determine how an entity moves within a scene
	*/
	typedef sf::Vector2f Vec2;
	struct CompMovement : Compoment {
	public:
		//sf shape used for rendering
		lny::Vec2 velocity;
		CompMovement(Vec2 vel) :velocity(vel) {
			isActive = true;

		};


	};
}