#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include "../BaseMediaManager.hpp"
namespace lny {
	/*
	* MediaManager manages texture images and other kinds of external media used by a scene
	*/
	class TextureManager : public lny::BaseMediaManager<std::shared_ptr<sf::Texture>>
	{
	public:

		//constructor using texture file path
		TextureManager() :BaseMediaManager<std::shared_ptr<sf::Texture>>() {};

		//inserts a texture into textures
		void loadTexture(std::string name,std::string path);

		//unloads one texture
		void unloadTexture(std::string name);

		//unloads all textures in the textures map
		void dumpTextures();

		//method that returns a pointer to a texture in the texture map
		sf::Texture* getTexture(std::string texName);
	};
}
