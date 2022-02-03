#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Component.hpp"
namespace lny {
	typedef sf::Vector2f Vec2;
	/*
	* transform component used to apply transfroms to the entity
	*/
	struct CompTransform : Compoment {
		// xy position of entity
		Vec2 pos;
		float xvel = 0;
		float yvel = 0;
		//rotation of the entity around its shape component center
		float rotation = 0.f;
		CompTransform(Vec2 p, float r) : pos(p), rotation(r) { isActive = true; };
	};
}