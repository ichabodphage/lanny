#pragma once
#include "engine/BaseScene.hpp"
#include "engine/LannyEngine.hpp"
enum objectIDs {
	RECT
};
enum eventIDs {
	KEY_A,
	KEY_D,
	KEY_W,
	KEY_S
};
class RectScene : public lny::BaseScene {
public:
	RectScene(lny::EngineWindow localWindow,lny::LannyEngine * engine):BaseScene(localWindow, engine){}
	void init() {
		registerKeyEvent(sf::Keyboard::A, KEY_A);
		registerKeyEvent(sf::Keyboard::D, KEY_D);
		registerKeyEvent(sf::Keyboard::W, KEY_W);
		registerKeyEvent(sf::Keyboard::S, KEY_S);

		auto rect = entityManager->insertEntity(RECT);
		rect->cPosition = std::make_shared<lny::CompPosition>(lny::XyVector(10,10));
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
	void reciveEvent(lny::Event myEvent) {
		auto rect = entityManager->getEntities(RECT)[0];
		switch (myEvent.name) {
		case KEY_A:
			if (myEvent.active) {
				rect->cPosition->velocityXy.x = -0.1f;
			}
			else {
				rect->cPosition->velocityXy.x = 0;
			}
			break;
		case KEY_D:
			if (myEvent.active) {
				rect->cPosition->velocityXy.x = 0.1f;
			}
			else {
				rect->cPosition->velocityXy.x = 0;
			}
			break;
		case KEY_W:
			if (myEvent.active) {
				rect->cPosition->velocityXy.y = -0.1f;
			}
			else {
				rect->cPosition->velocityXy.y = 0;
			}
			break;
		case KEY_S:
			if (myEvent.active) {
				rect->cPosition->velocityXy.y = 0.1f;
			}
			else {
				rect->cPosition->velocityXy.y = 0;
			}
			break;
		}
	}
};