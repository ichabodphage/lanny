#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace lny {
	/*
	* MediaManager manages texture images and other kinds of external media used by a scene
	*/
	class TextureManager
	{
	private:
		//map that holds all the textures
		std::map<std::string, std::shared_ptr<sf::Texture>> textures;
		
		//path to texture assets
		std::string textureFile;
	public:

		//constructor using texture file path
		TextureManager(std::string texPath) :textureFile(texPath) {};

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