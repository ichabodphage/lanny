#include "TextureManager.hpp"
#include <iostream>
using namespace lny;

void TextureManager::loadTexture(std::string name,std::string path) {
	try {
		textures.at(name);
		std::cout << "texture " << name << " allready loaded\n";
	}
	catch (std::exception e) {
		sf::Texture tex;
		//insert a texture if the file for that texture is found
		if (tex.loadFromFile(textureFile + "\\" + path)) {
			textures[name] = std::make_shared<sf::Texture>(tex);
		}
		std::cout << "texture " << name << " loaded from: " << textureFile<< "\\" <<  path <<"\n";
	}

}

sf::Texture* TextureManager::getTexture(std::string name) {
	try {
		auto ret = textures.at(name).get();

		return ret;
	}
	catch (std::exception e) {
		std::cout << "error, texture: " << name << " does not exist.\n";
	}
}

void TextureManager::unloadTexture(std::string name) {
	try {
		textures.erase(name);
		std::cout << "texture: " << name << " successfully unloaded\n";
	}
	catch (std::exception e) {
		std::cout << "error, texture: " << name << " does not exist.\n";
	}
}
void TextureManager::dumpTextures() {
	textures.clear();

}