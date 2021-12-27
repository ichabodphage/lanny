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
void LannyEngine::sendKeyPress(sf::Event * myKeyEvent) {
	try {
		auto current = scenes.at(currentScene);
		int eventName = current->events.at(myKeyEvent->key.code);
		bool isPressed = (myKeyEvent->type == sf::Event::KeyPressed) ? true : false;
		current->reciveEvent(lny::Event(eventName, isPressed));
	}
	catch (std::exception e) {

	};
}
void LannyEngine::input() {
	sf::Event event;
	while (window->pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::KeyPressed:
				sendKeyPress(&event);
				break;
			case sf::Event::KeyReleased:
				sendKeyPress(&event);
				break;
		}
	}
}