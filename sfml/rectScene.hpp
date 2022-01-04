#pragma once
#include "engine/BaseScene.hpp"
#include "engine/LannyEngine.hpp"
#include "engine/Entity/Entity.hpp"
#include <random>
enum objectIDs {
	RECT,
	ENEMY,
	PLAYER
};
enum eventIDs {
	END,
	INSERT_RECT,
	RECOLOR_RECT
};
class RectScene : public lny::BaseScene {
public:
	RectScene(lny::EngineWindow localWindow,lny::LannyEngine * engine,lny::MediaManager * media):BaseScene(localWindow, engine,media){}


	void init() {
		registerKeyEvent(sf::Keyboard::Escape, END);
		for (int i = 0; i < 5000; i++) {
			lny::Entity rect = entityManager->addEntity();
			rect.getComponent<lny::CompShape>() = lny::CompShape({ 100,100 });
			rect.getComponent<lny::CompTransform>() = lny::CompTransform(lny::Vec2(i, i),0);

		}
		start();
	}


	void run() {
		globalEngine->input();
		render();


	}

	void reciveEvent(lny::Event myEvent) {
		switch (myEvent.name) {
		case END:
			kill();
			break;
		}
	}
};