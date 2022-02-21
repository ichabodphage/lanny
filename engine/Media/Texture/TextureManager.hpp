#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include "../BaseMediaManager.hpp"
#include "../../Renderer/Texture.hpp"
namespace lny {
	/*
	* Texture manager is an extention of BaseMediaManager using
	* lny::Texture. manages loading of textures.
	*/
	class TextureManager : public lny::BaseMediaManager<lny::Texture>
	{
	public:

		//constructor using texture file path
		TextureManager() :BaseMediaManager<lny::Texture>() {};

		//inserts a texture into textures
		void loadTexture(std::string name,std::string path);

		//unloads one texture
		void unloadTexture(std::string name);

		//unloads all textures in the textures map
		void dumpTextures();

		//method that returns a pointer to a texture in the texture map
		lny::Texture* getTexture(std::string texName);
	};
}
