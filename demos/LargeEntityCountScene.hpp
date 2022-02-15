#pragma once
#include "../engine/Scene/BaseScene.hpp"
#include "../engine/LannyEngine.hpp"
#include "../engine/Entity/Entity.hpp"
#include "../engine/Renderer/RenderBatch.hpp"
#include <random>
#include <chrono>
#include <iostream>

class LargeEntityCountScene : public lny::BaseScene {
public:
	LargeEntityCountScene(lny::EngineWindow  localWindow, lny::LannyEngine* engine, lny::GLOBAL_MEDIA* media, lny::ComponentMgr* w) :BaseScene(localWindow, engine, media, w),localBatch(w->getEntityLimit()) {}
	float dt = 0.f;
	lny::RenderBatch localBatch;
	void init() {
		registerInputEvent(lny::eventType::keyEvent, sf::Keyboard::Escape, END);
		registerInputEvent(lny::eventType::keyEvent, sf::Keyboard::Num1, CHANGE_SCENE);
		registerInputEvent(lny::eventType::keyEvent, sf::Keyboard::Num2, GET_FPS);
		for (int i = 0; i < 100; i += 1) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < 10; k++) {
					lny::Entity rect = entityManager->addEntity();
					rect.getComponent<lny::CompShape>() = lny::CompShape(lny::Vec2(50,50));
					rect.getComponent<lny::CompShape>().shape.setFillColor(sf::Color(255, 255, 255));
					rect.getComponent<lny::CompTransform>() = lny::CompTransform(lny::Vec2(10 + j*50 , 10 + k * 50), 0);
					
				}
			}
		}
		for (auto& entity : entityManager->entities) {
			//render entity if the entity has a shape
			if (entity.hasComponent<lny::CompShape>()) {
				auto loc = entity.getComponent<lny::CompShape>();
				if (entity.hasComponent<lny::CompTransform>()) {
					loc.shape.setPos(entity.getComponent<lny::CompTransform>().pos);
				}
				localBatch.addVerticies(&loc.shape);
			}
		}
	}
	
	void render() {
		window->clear();
	
		window->draw(localBatch.getVerticies().data(), localBatch.size(), sf::Quads);
		window->display();
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
			
				globalEngine->playScene("scene4");
			}
			break;
		case GET_FPS:
			if (!myEvent.active) {
				getFrameRate();
			}
			break;
		}
	}
};