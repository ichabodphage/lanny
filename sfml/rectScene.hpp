#pragma once
#include "engine/BaseScene.hpp"
#include "engine/LannyEngine.hpp"
#include <random>
enum objectIDs {
	RECT,
	ENEMY,
	PLAYER
};
enum eventIDs {
	MOV_LEFT,
	MOV_RIGHT,
	MOV_UP,
	MOV_DOWN,
	END,
	INSERT_RECT
};
class RectScene : public lny::BaseScene {
public:
	RectScene(lny::EngineWindow localWindow,lny::LannyEngine * engine,lny::MediaManager * media):BaseScene(localWindow, engine,media){}


	void init() {
		globalMedia->insertTexture("crate0_diffuse.png");
		//register key events
		registerKeyEvent(sf::Keyboard::Escape,END);
		registerKeyEvent(sf::Keyboard::A, MOV_LEFT);
		registerKeyEvent(sf::Keyboard::D, MOV_RIGHT);
		registerKeyEvent(sf::Keyboard::W, MOV_UP);
		registerKeyEvent(sf::Keyboard::S, MOV_DOWN);
		registerKeyEvent(sf::Keyboard::U, INSERT_RECT);
		
		initRectangle({ 10,10 }, { 200,100 });
		//start game loop
		start();
	}
	void move(){
		auto rect = entityManager->getEntities()[0];
		rect->cPosition->positionXy += rect->cPosition->velocityXy;
		rect->cShape->shape.setPosition(rect->cPosition->positionXy);
		
	}
	void initRectangle(lny::XyVector pos, lny::XyVector size) {
		//insert rect into engine
		auto rect = entityManager->insertEntity(RECT);
		rect->cPosition = std::make_shared<lny::CompPosition>(pos);
		rect->cShape = std::make_shared<lny::CompShape>();
		rect->cTexture = std::make_shared<lny::CompTexture>(globalMedia->getTexture("crate0_diffuse.png"));
		rect->cShape->rect(size);
		rect->cShape->shape.setTexture(rect->cTexture->texture.get());
		rect->cShape->tint(sf::Color(randomFloat(0,255), randomFloat(0, 255), randomFloat(0, 255)));
		rect->cShape->shape.setPosition(rect->cPosition->positionXy);
	}

	void run() {
		globalEngine->input();
		render();
		move();
	}
	void reciveEvent(lny::Event myEvent) {
		auto rect = entityManager->getEntities(RECT)[0];
		switch (myEvent.name) { //keyboard input handler
		case MOV_LEFT:
			if (myEvent.active) {
				rect->cPosition->velocityXy.x = -0.1f;
			}
			else {
				rect->cPosition->velocityXy.x = 0;
			}
			break;
		case MOV_RIGHT:
			if (myEvent.active) {
				rect->cPosition->velocityXy.x = 0.1f;
			}
			else {
				rect->cPosition->velocityXy.x = 0;
			}
			break;
		case MOV_UP:
			if (myEvent.active) {
				rect->cPosition->velocityXy.y = -0.1f;
			}
			else {
				rect->cPosition->velocityXy.y = 0;
			}
			break;
		case MOV_DOWN:
			if (myEvent.active) {
				rect->cPosition->velocityXy.y = 0.1f;
			}
			else {
				rect->cPosition->velocityXy.y = 0;
			}
			break;
		case END:
			kill();
			break;
		case INSERT_RECT:
			initRectangle({ randomFloat(0, 1280) ,randomFloat(0, 720) }, {randomFloat(0,100),randomFloat(0,100) });
			break;
		}
	}
	float randomFloat(float min, float max) {
		std::random_device rd;
		std::default_random_engine gen(rd());
		std::uniform_real_distribution<> dist(min, max);
		return dist(gen);
	}

	float randomint(int min, int max) {
		std::random_device rd;
		std::default_random_engine gen(rd());
		std::uniform_int_distribution<> dist(min, max);
		return dist(gen);
	}
};