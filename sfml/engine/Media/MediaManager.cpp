#include "MediaManager.hpp"
#include <iostream>
using namespace lny;

void MediaManager::insertTexture(std::string name) {
	sf::Texture tex;
	if (tex.loadFromFile(textureFile + "\\" + name)) {
		textures[name] = std::make_shared<sf::Texture>(tex);
	}

}

std::shared_ptr<sf::Texture> MediaManager::getTexture(std::string name) {
	try {
		return textures.at(name);
	}
	catch (std::exception e) {

	}
}