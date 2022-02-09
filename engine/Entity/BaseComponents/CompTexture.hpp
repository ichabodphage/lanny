#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Component.hpp"
namespace lny {
	typedef sf::Vector2f Vec2;
	/*
	* transform component used to apply transfroms to the entity
	*/
	struct CompTexture : Compoment {
		sf::Texture* texture;
		CompTexture(sf::Texture* tex):texture(tex){ isActive = true;
		};
	};
}