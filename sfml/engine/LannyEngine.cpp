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
void LannyEngine::sendKeyPress(sf::Event * myKeyEvent, bool isPressed) {
	try {
		//get current scene
		auto current = scenes.at(currentScene);
		
		//pool events for the keycode of the key pressed, throw an exeption and continue if otherwise
		int eventName = current->events.at(myKeyEvent->key.code);
		
		//send event with isPressed and eventName
		current->reciveEvent(lny::Event(eventName, isPressed));
	}
	catch (std::exception e) {

	};
}
void LannyEngine::input() {
	sf::Event event;
	while (window->pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed: //close window 
				window->close();
				break;
			case sf::Event::KeyPressed:
				sendKeyPress(&event,true);
				break;
			case sf::Event::KeyReleased:
				sendKeyPress(&event,false);
				break;
			case sf::Event::Resized:
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window->setView(sf::View(visibleArea));
				break;
		}
	}
}