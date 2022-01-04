#include "BaseScene.hpp"
#include "LannyEngine.hpp"
using namespace lny;

void BaseScene::render() {
	window->clear();
	//loop through all entities in the entity manager
	for (auto& entity : entityManager->entities) {
		//render entity if the entity has a shape
		if (entity->cShape && entity->cPosition) {
			sf::Transform trans;
			sf::RenderStates entityRender;
			entityRender.transform = trans.translate(entity->cPosition->pos).rotate(entity->cPosition->rotation, entity->cShape->center);
			if (entity->cTexture) {
				entityRender.texture = entity->cTexture->texture.get();
			}
			window->draw(entity->cShape->verticies
				, entityRender
			);
		}
	}
	window->display();
}



void BaseScene::init() {
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
		run();
	}
}

void BaseScene::kill() {
	//setting isRunning to false ends the scene loop
	isRunning = false;
}
void BaseScene::run() {
	render();
}
void BaseScene::reciveEvent(Event myEvent) {
	std::string status = (myEvent.active) ? " and active" : " and not active";
	std::cout << "event with code: " <<std::to_string(myEvent.name) << status << "\n";
}