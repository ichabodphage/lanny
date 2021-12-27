#include "BaseScene.hpp"
using namespace lny;

void BaseScene::render() {
	window->clear();
	for (auto& entity : entityManager->entities) {
		if (entity->cShape) {
			window->draw(entity->cShape->shape);
		}
	}
	window->display();
}

void BaseScene::init() {
	start();
}

void BaseScene::start() {
	isRunning = true;
	sceneLoop();
}

void BaseScene::sceneLoop() {
	while (isRunning && window->isOpen()) {
		run();
	}
}
void BaseScene::kill() {
	isRunning = false;
}
void BaseScene::run() {
	render();
}