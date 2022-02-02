#include "LannyEngine.hpp"

using namespace lny;


void LannyEngine::playScene(std::string sceneName) {
	//get the new scene
	try {
		auto newScene = scenes.at(sceneName);

		//kill the current scene if a scene is loaded
		if (currentScene) {
			currentScene->kill();
		}
		//save the name of the current scene and run init
		currentScene = newScene;
		currentScene->init();
		std::cout << "successfully started scene: " << sceneName << "\n";
		runScene();
	}
	catch (std::exception e) {
		std::cout << "error, scene " << sceneName << " is not defined \n";
	};
}


void LannyEngine::incrementFrame() {
	frame++;
}

size_t LannyEngine::getCurrentFrame() {
	return frame;
}


void LannyEngine::sendKeyPress(sf::Event * myKeyEvent, bool isPressed) {
	//try block catches any exceptions if the current scene is not found in the map
	try {
		//poll events for the keycode of the key pressed, throw an exeption and continue if otherwise
		int eventName = currentScene->keyEvents.at(myKeyEvent->key.code);
		//send event with isPressed and eventName
		currentScene->reciveInput(lny::Event(eventName, isPressed));
	}
	catch (std::exception e) {

	};
}

void LannyEngine::sendMouseEvent(sf::Event* myMouseEvent, bool isPressed,lny::Vec2 mag) {
	try {
		//poll events for the keycode of the key pressed, throw an exeption and continue if otherwise
		int eventName = currentScene->mouseEvents.at(myMouseEvent->mouseButton.button);
		//send event with isPressed and eventName
		currentScene->reciveInput(lny::Event(eventName, isPressed,mag));
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
			case sf::Event::MouseButtonPressed: // mouse pressed
				sendMouseEvent(&event, true, { (float)event.mouseButton.x,(float)event.mouseButton.y });
				break;
			case sf::Event::MouseButtonReleased: //mouse unpressed
				sendMouseEvent(&event, false, { (float)event.mouseButton.x,(float)event.mouseButton.y });
				break;
		}
	}
}

void LannyEngine::runScene() {
	sf::Clock timer;
	while (window->isOpen() && currentScene->isOn()) {
		currentScene->run_frameIndependant();
		currentScene->run(timer.getElapsedTime().asSeconds());
		timer.restart();
	}
}