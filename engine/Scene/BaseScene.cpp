#include "BaseScene.hpp"
#include "../LannyEngine.hpp"
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
	std::cout << "SCENE INIT TEST GONE RIGHT\n";
}
void BaseScene::registerInputEvent(enum eventType type,int key, int eventName) {
	switch (type) {
	case keyEvent:
		keyEvents[key] = eventName;
		break;
	case mouseEvent:
		mouseEvents[key] = eventName;
		break;
	}
	
}


void BaseScene::kill() {
	//setting isRunning to false ends the scene loop
	entityManager->deInit();
	isRunning = false;
}

void BaseScene::run_frameIndependant() {
	globalEngine->input();
	entityManager->sweepInactive();
	render();
}
void BaseScene::run(float deltaT) {
	
}
void BaseScene::reciveInput(Event myEvent) {
	std::string status = (myEvent.active) ? " and active" : " and not active";
	std::cout << "event with code: " <<std::to_string(myEvent.name) << status << "\n";
}