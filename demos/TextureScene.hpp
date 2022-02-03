#pragma once
#include "../engine/Scene/BaseScene.hpp"
#include "../engine/LannyEngine.hpp"
#include "../engine/Entity/Entity.hpp"
#include <random>
#include <chrono>
#include <thread>
class TextureScene : public lny::BaseScene {
public:
	TextureScene(lny::EngineWindow localWindow, lny::LannyEngine* engine, lny::MediaManager* media,lny::ComponentMgr * w) :BaseScene(localWindow, engine, media,w) {}

	float dt;
	void init() {
		registerInputEvent(lny::eventType::keyEvent, sf::Keyboard::Escape, END);
		registerInputEvent(lny::eventType::keyEvent, sf::Keyboard::Num1, CHANGE_SCENE);
		registerInputEvent(lny::eventType::keyEvent, sf::Keyboard::Num2, GET_FPS);

		for (int i = 0; i < 200; i+=10) {
			lny::Entity rect = entityManager->addEntity();
			rect.getComponent<lny::CompShape>() = lny::CompShape({ 50,50 });
			rect.getComponent<lny::CompShape>().shape.setTexture(globalMedia->globalTextures.getTexture("box"));
			rect.getComponent<lny::CompShape>().shape.setFillColor(sf::Color(255 - i, 255, 255));
			rect.getComponent<lny::CompTransform>() = lny::CompTransform(lny::Vec2(10, 10 +i*5), 0);

		}
	

		for (int j = 0; j < 200; j += 10) {
			lny::Entity rect2 = entityManager->addEntity();
			rect2.getComponent<lny::CompShape>() = lny::CompShape({ 50,50 });
			rect2.getComponent<lny::CompShape>().shape.setTexture(globalMedia->globalTextures.getTexture("pen"));
			rect2.getComponent<lny::CompShape>().shape.setFillColor(sf::Color(255, 255 - j, 255));
			rect2.getComponent<lny::CompTransform>() = lny::CompTransform(lny::Vec2(120, 10 + j * 5), 0);
		}

		for (int j = 0; j < 200; j += 10) {
			lny::Entity rect2 = entityManager->addEntity();
			rect2.getComponent<lny::CompShape>() = lny::CompShape({ 100,50 });
			rect2.getComponent<lny::CompShape>().shape.setTexture(globalMedia->globalTextures.getTexture("car"));
			rect2.getComponent<lny::CompShape>().shape.setFillColor(sf::Color(255, 255, 255 - j));
			rect2.getComponent<lny::CompTransform>() = lny::CompTransform(lny::Vec2(220, 10 + j * 5), 0);
		}

	
	}
	void run_frameIndependant() {
		globalEngine->input();
		entityManager->sweepInactive();
		render();
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	void run(float deltaT) {
		dt = deltaT;

	}
	void getFrameRate() {
		std::cout << "current frames per second: " << 1 / dt << "\n";
	}
	void reciveInput(lny::Event myEvent) {
		switch (myEvent.name) {
		case END:
			kill();
			break;
		case CHANGE_SCENE:
			if (myEvent.active) {
				globalEngine->playScene("scene3");
			}
			break;
		case GET_FPS:
			if (myEvent.active) {
				getFrameRate();
			}
			break;
		}
	}
};