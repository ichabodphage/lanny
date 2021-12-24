#pragma once
#include "engine/BaseScene.hpp"
#include "LannyEngine.hpp"

class RectScene : public lny::BaseScene {
public:
	RectScene(EngineWindow localWindow):BaseScene(localWindow){}
	void init() {
		auto rect = entityManager->insertEntity(0);
		rect->cPosition = std::make_shared<lny::CompPosition>(XyVector(10,10));
		rect->cShape = std::make_shared<lny::CompShape>();
		rect->cShape->rect({ 100, 100 });
		rect->cShape->tint(sf::Color(255, 0, 0));
		rect->cShape->shape.setPosition(rect->cPosition->positionXy);
		isRunning = true;
		sceneLoop();
	}
	void run() {
		render();
	}
};