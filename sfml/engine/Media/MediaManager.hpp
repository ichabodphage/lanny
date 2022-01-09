#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace lny {
	/*
	* MediaManager manages texture images and other kinds of external media used by a scene
	*/
	class MediaManager
	{
	private:
		//map that holds all the textures
		std::map<std::string, std::shared_ptr<sf::Texture>> textures;
		//path to texture assets
		std::string textureFile;
	public:

		//constructor using texture file path
		MediaManager(std::string texPath) :textureFile(texPath) {};

		//inserts a texture into textures
		void insertTexture(std::string texName);

		//method that returns a pointer to a texture in the texture map
		std::shared_ptr<sf::Texture> getTexture(std::string texName);
	};
}
