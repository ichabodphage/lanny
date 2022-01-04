#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Component.hpp"
namespace lny {
	/*
	* texture entity component used to apply textures onto entities
	*/
	struct CompTexture : Compoment {
		std::shared_ptr<sf::Texture> texture;
		CompTexture(std::shared_ptr<sf::Texture> tex) :texture(tex) {};
	};
}