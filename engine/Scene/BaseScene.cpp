#include "BaseScene.hpp"
#include "../LannyEngine.hpp"
using namespace lny;

void BaseScene::render() {
	window->clear();
	//loop through all entities in the entity manager
	for (auto& entity : entityManager->entities) {
		//render entity if the entity has a shape
		if (entity.hasComponent<lny::CompShape>()) {
			auto loc = entity.getComponent<lny::CompShape>();
			if (entity.hasComponent<lny::CompTransform>()) {
				loc.shape.setPos(entity.getComponent<lny::CompTransform>().pos);
			}
			
			
			//window->draw(loc.shape.getPoints(), loc.shape.getTexture());
			
		}
	}
	window->display();
}



void BaseScene::init() {
	std::cout << "SCENE INIT TEST GONE RIGHT\n";
}


void BaseScene::kill() {
	//setting isRunning to false ends the scene loop
	entityManager->deInit();
	isRunning = false;
}

void BaseScene::run_frameIndependant() {
	entityManager->sweepInactive();
	localRenderer.render();
}
void BaseScene::run(float deltaT) {
	
}
