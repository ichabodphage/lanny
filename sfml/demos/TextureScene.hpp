#pragma once
#include "../engine/BaseScene.hpp"
#include "../engine/LannyEngine.hpp"
#include "../engine/Entity/Entity.hpp"
#include <random>

class TextureScene : public lny::BaseScene {
public:
	TextureScene(lny::EngineWindow  localWindow, lny::LannyEngine* engine, lny::MediaManager* media,lny::ComponentMgr * w) :BaseScene(localWindow, engine, media,w) {}

	
	void init() {
		registerKeyEvent(sf::Keyboard::Escape, END);
		registerKeyEvent(sf::Keyboard::Num1, CHANGE_SCENE);


		globalMedia->insertTexture("crate0_diffuse.png");
		globalMedia->insertTexture("pen.jpg");
		globalMedia->insertTexture("car1_spr.png");
		for (int i = 0; i < 200; i+=10) {
			lny::Entity rect = entityManager->addEntity();
			rect.getComponent<lny::CompShape>() = lny::CompShape({ 50,50 });
			rect.getComponent<lny::CompShape>().shape.setTexture(globalMedia->getTexture("crate0_diffuse.png").get());
			rect.getComponent<lny::CompShape>().shape.setFillColor(sf::Color(255 - i, 255, 255));
			rect.getComponent<lny::CompTransform>() = lny::CompTransform(lny::Vec2(10, 10 +i*5), 0);

		}
	

		for (int j = 0; j < 200; j += 10) {
			lny::Entity rect2 = entityManager->addEntity();
			rect2.getComponent<lny::CompShape>() = lny::CompShape({ 50,50 });
			rect2.getComponent<lny::CompShape>().shape.setTexture(globalMedia->getTexture("pen.jpg").get());
			rect2.getComponent<lny::CompShape>().shape.setFillColor(sf::Color(255, 255 - j, 255));
			rect2.getComponent<lny::CompTransform>() = lny::CompTransform(lny::Vec2(120, 10 + j * 5), 0);
		}

		for (int j = 0; j < 200; j += 10) {
			lny::Entity rect2 = entityManager->addEntity();
			rect2.getComponent<lny::CompShape>() = lny::CompShape({ 100,50 });
			rect2.getComponent<lny::CompShape>().shape.setTexture(globalMedia->getTexture("car1_spr.png").get());
			rect2.getComponent<lny::CompShape>().shape.setFillColor(sf::Color(255, 255, 255 - j));
			rect2.getComponent<lny::CompTransform>() = lny::CompTransform(lny::Vec2(220, 10 + j * 5), 0);
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
			globalEngine->loadScene("scene3");
			break;
		}
	}
};