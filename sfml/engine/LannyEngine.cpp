#include "LannyEngine.hpp"
#include <random>
#include <iostream>
using namespace lny;

void LannyEngine::insertScene(std::string sceneName, ScenePtr scene) {
	scenes[sceneName] = scene;
}

void LannyEngine::loadScene(std::string sceneName) {
	//get the new scene
	auto newScene = scenes.at(sceneName);

	//kill the current scene if a scene is loaded
	if (currentScene) {
		currentScene->kill();
	}
	//save the name of the current scene and run init
	currentScene = newScene;
	currentScene->init();
}



ScenePtr LannyEngine::getScene(std::string sceneName) {
	//catch for exeption if sceneName is not in scenes
	try {
		return scenes.at(sceneName);
	}
	catch (std::exception e) {
		std::cout << "error, scene: " << sceneName << " does not exist\n";
	};
}

ScenePtr LannyEngine::getCurrentScene() {
	return currentScene;
}

void LannyEngine::incrementFrame() {
	frame++;
}

unsigned long long LannyEngine::getCurrentFrame() {
	return frame;
}


void LannyEngine::sendKeyPress(sf::Event * myKeyEvent, bool isPressed) {
	//try block catches any exceptions if the current scene is not found in the map
	try {
		//poll events for the keycode of the key pressed, throw an exeption and continue if otherwise
		int eventName = currentScene->events.at(myKeyEvent->key.code);
		//send event with isPressed and eventName
		currentScene->reciveEvent(lny::Event(eventName, isPressed));
	}
	catch (std::exception e) {

	};
}


void LannyEngine::input() {
	sf::Event event;
	while (window->pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:			//close window 
				window->close();
				break;
			case sf::Event::KeyPressed:		//key down
				sendKeyPress(&event,true);
				break;
			case sf::Event::KeyReleased:	//key up
				sendKeyPress(&event,false);
				break;
			case sf::Event::Resized:		// window resized
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window->setView(sf::View(visibleArea));
				break;
		}
	}
}