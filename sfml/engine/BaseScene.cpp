#include "BaseScene.hpp"
#include "LannyEngine.hpp"
#include <iostream>
#include "Entity/ComponentManager.hpp"

using namespace lny;

void BaseScene::render() {
	window->clear();
	//loop through all entities in the entity manager
	for (auto& entity : entityManager->entities) {
		//render entity if the entity has a shape
		if (entity.hasComponent<lny::CompShape>()) {
			sf::RectangleShape loc = entity.getComponent<lny::CompShape>().shape;
			sf::Transform	   shapeTransform;

			window->draw(loc, shapeTransform.translate(entity.getComponent<lny::CompTransform>().pos));
		}
	}
	window->display();
}



void BaseScene::init() {
	//just run the start function in the base scene
	start();
}

void BaseScene::start() {
	//set is running to true and call scene loop to begin the scene
	isRunning = true;
	sceneLoop();
}

void BaseScene::registerKeyEvent(int key, int eventName) {
	events[key] = eventName;
}

void BaseScene::sceneLoop() {
	//loop that only ends if the window is closed or the scene is nolonger running
	while (isRunning && window->isOpen()) {
		globalEngine->incrementFrame();
		entityManager->sweepInactive();
		run();
	}
}

void BaseScene::kill() {
	//setting isRunning to false ends the scene loop
	entityManager->deInit();
	isRunning = false;
}
void BaseScene::run() {
	render();
}
void BaseScene::reciveEvent(Event myEvent) {
	std::string status = (myEvent.active) ? " and active" : " and not active";
	std::cout << "event with code: " <<std::to_string(myEvent.name) << status << "\n";
}