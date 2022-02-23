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



void LannyEngine::input() {
	sf::Event event;
	while (window->pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:		//close window 
				window->close();
				break;
			case sf::Event::KeyPressed:
				currentScene->sceneInput.reciveInput(event.key.code);
		}
	}
}

/*
void LannyEngine::delayFor(long ms){
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
*/



void LannyEngine::runScene() {
	sf::Clock timer;
	while (window->isOpen() && currentScene->isOn()) {
		input();
		currentScene->run_frameIndependant();
		currentScene->run(timer.getElapsedTime().asSeconds());
		timer.restart();
	}
}