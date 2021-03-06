#include "TextureManager.hpp"
#include <iostream>
using namespace lny;

void TextureManager::loadTexture(std::string name,std::string path) {
	try {
		//check if texture is allready loaded
		assets.at(name);
		std::cout << "texture " << name << " allready loaded\n";
	}
	catch (std::exception e) {
		//load the texture if the texture is not allready loaded
		sf::Texture tex;
		if (tex.loadFromFile(assetFolder + "/" + path)) {
			//insert the texture into the map if the path is valid
			assets[name] = lny::Texture(std::make_shared<sf::Texture>(tex));
			std::cout << "texture " << name << " loaded from: " << assetFolder << "/" <<  path <<"\n";
		}else{
			std::cout << "error, file path: " << assetFolder + "/" + path << " is an invalid texture path.\n";
		}
	}

}

lny::Texture* TextureManager::getTexture(std::string name) {
	lny::Texture* ret;
	try {
		//try accessing the texture with name from the texture map
		ret = &assets.at(name);
		return ret;
	}
	catch (std::exception e) {
		//return a nullptr and log an exception if it is not in the map
		std::cout << "error, texture: " << name << " is not defined.\n";
		return nullptr;
	}
}

void TextureManager::unloadTexture(std::string name) {
	try {
		//erease the texture at name if the texture is loaded
		assets.erase(name);
		std::cout << "texture: " << name << " successfully unloaded\n";
	}
	catch (std::exception e) {
		//log an exception if the texture is not loaded
		std::cout << "error, texture: " << name << " is not defined\n";
	}
}
void TextureManager::dumpTextures() {
	//clear the texture map
	assets.clear();

}