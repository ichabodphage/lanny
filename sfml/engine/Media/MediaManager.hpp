#pragma once
#include <SFML/Graphics.hpp>
#include <string>
namespace lny {
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

		void insertTexture(std::string texName);

		std::shared_ptr<sf::Texture> getTexture(std::string texName);
	};
}
