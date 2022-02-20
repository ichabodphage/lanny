#pragma once
#include <SFML/Graphics.hpp>

namespace lny {
	typedef sf::Vector2u Vec2u;
	/*
	* struct used by the texture manager to hold textures, contains a pointer to a sf texture 
	* along with the cordinates of the texure on the texture file
	*/

	struct Texture {
		//pointer to the texture in memory
		std::shared_ptr<sf::Texture> textureImage;
		//offset location of the texture (used for texture atlasses and spritesheets for referencing different textures)
		lny::Vec2u offset;
		//size of the texture;
		lny::Vec2u size;

		//constructor using texture pointer and position
		Texture(std::shared_ptr<sf::Texture> text, lny::Vec2u pos) : textureImage(text), size(text->getSize()),offset(pos) {};

		//constructor using just the texture
		Texture(std::shared_ptr<sf::Texture> text) : textureImage(text), size(text->getSize()), offset(lny::Vec2u(0,0)) {};

		Texture() :textureImage(nullptr), offset(lny::Vec2u(0, 0)), size(lny::Vec2u(0, 0)) {};
	};
}