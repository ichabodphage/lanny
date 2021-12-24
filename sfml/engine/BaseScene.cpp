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
	isRunning = true;
	sceneLoop();
}
void BaseScene::sceneLoop() {
	while (isRunning) {
		run();
	}
}

void BaseScene::run() {
	render();
}