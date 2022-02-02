#include "TextureManager.hpp"
#include <iostream>
using namespace lny;

void TextureManager::loadTexture(std::string name,std::string path) {
	try {
		//check if texture is allready loaded
		textures.at(name);
		std::cout << "texture " << name << " allready loaded\n";
	}
	catch (std::exception e) {
		//load the texture if the texture is not allready loaded
		sf::Texture tex;
		if (tex.loadFromFile(textureFile + "/" + path)) {
			//insert the texture into the map if the path is valid
			textures[name] = std::make_shared<sf::Texture>(tex);
			std::cout << "texture " << name << " loaded from: " << textureFile<< "/" <<  path <<"\n";
		}else{
			std::cout << "error, file path: " << textureFile + "/" + path << " is an invalid texture path. (does " <<textureFile + "/" + path << " exist or is in a supported file format?)\n";
		}
	}

}

sf::Texture* TextureManager::getTexture(std::string name) {
	sf::Texture* ret;
	try {
		//try accessing the texture with name from the texture map
		ret = textures.at(name).get();
		return ret;
	}
	catch (std::exception e) {
		//return a nullptr and log an exception if it is not in the map
		std::cout << "error, texture: " << name << " is not a texture that has been loaded into the texture manager.\n";
		return nullptr;
	}
}

void TextureManager::unloadTexture(std::string name) {
	try {
		//erease the texture at name if the texture is loaded
		textures.erase(name);
		std::cout << "texture: " << name << " successfully unloaded\n";
	}
	catch (std::exception e) {
		//log an exception if the texture is not loaded
		std::cout << "error, texture: " << name << " not loaded into texture manager. (cannot delete texture that does not exist)\n";
	}
}
void TextureManager::dumpTextures() {
	//clear the texture map
	textures.clear();

}