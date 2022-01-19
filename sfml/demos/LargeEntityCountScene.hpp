#pragma once
#include "../engine/BaseScene.hpp"
#include "../engine/LannyEngine.hpp"
#include "../engine/Entity/Entity.hpp"
#include <random>

class LargeEntityCountScene : public lny::BaseScene {
public:
	LargeEntityCountScene(lny::EngineWindow  localWindow, lny::LannyEngine* engine, lny::MediaManager* media, lny::ComponentMgr* w) :BaseScene(localWindow, engine, media, w) {}


	void init() {
		registerKeyEvent(sf::Keyboard::Escape, END);
		registerKeyEvent(sf::Keyboard::Num1, CHANGE_SCENE);


		globalMedia->insertTexture("crate0_diffuse.png");
		globalMedia->insertTexture("pen.jpg");
		globalMedia->insertTexture("car1_spr.png");
		for (int i = 0; i < 1000; i += 1) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < 10; k++) {
					lny::Entity rect = entityManager->addEntity();
					rect.getComponent<lny::CompShape>() = lny::CompShape({ 50,50 });
					rect.getComponent<lny::CompShape>().shape.setTexture(globalMedia->getTexture("crate0_diffuse.png").get());
					rect.getComponent<lny::CompShape>().shape.setFillColor(sf::Color(255, 255, 255));
					rect.getComponent<lny::CompTransform>() = lny::CompTransform(lny::Vec2(10 + j*50 , 10 + k * 50), 0);
					
				}
			}
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
		case CHANGE_SCENE:
			kill();
			globalEngine->loadScene("scene1");
			break;
		}
	}
};