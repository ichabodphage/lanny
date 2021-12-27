#pragma once
#include "engine/BaseScene.hpp"
#include "engine/LannyEngine.hpp"
enum objectIDs {
	RECT
};
class RectScene : public lny::BaseScene {
public:
	RectScene(lny::EngineWindow localWindow,lny::LannyEngine * engine):BaseScene(localWindow, engine){}
	void init() {
		auto rect = entityManager->insertEntity(RECT);
		rect->cPosition = std::make_shared<lny::CompPosition>(lny::XyVector(10,10), lny::XyVector(0.01f,0.01f));
		rect->cShape = std::make_shared<lny::CompShape>();
		rect->cShape->rect({ 100, 100 });
		rect->cShape->tint(sf::Color(255, 0, 0));
		rect->cShape->shape.setPosition(rect->cPosition->positionXy);
		start();
	}
	void move(){
		auto rect = entityManager->getEntities()[0];
		rect->cPosition->positionXy += rect->cPosition->velocityXy;
		rect->cShape->shape.setPosition(rect->cPosition->positionXy);
		
	}
	void run() {
		localEngine->input();
		render();
		move();
	}
};