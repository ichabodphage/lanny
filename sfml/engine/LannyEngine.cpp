#include "LannyEngine.hpp"
#include <random>
#include <iostream>
using namespace lny;

void LannyEngine::insertScene(std::string sceneName, ScenePtr scene) {
	scenes[sceneName] = scene;
}

void LannyEngine::loadScene(std::string sceneName) {
	auto localScene = scenes.at(sceneName);
	if (currentScene != "") {
		scenes.at(currentScene)->kill();
	}
	currentScene = sceneName;
	localScene->init();
}

ScenePtr LannyEngine::getCurrentScene(std::string sceneName) {
	return scenes.at(sceneName);
}

void LannyEngine::input() {
	sf::Event event;
	while (window->pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::KeyPressed:
				std::cout << event.key.code << "\n";
				break;
		}
	}
}