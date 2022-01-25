#pragma once
#include "../engine/BaseScene.hpp"
#include "../engine/LannyEngine.hpp"
#include "../engine/Entity/Entity.hpp"
#include <random>
#include <iostream>
#include <chrono>
#include <thread>
enum keyeventIDs {
	END,
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT,
	CHANGE_SCENE,
	GET_FPS,
	PLAY_SONG,
	PAUSE_SONG,
	STOP_SONG,
	COLIDE_CURSOR
};
class ColisonScene: public lny::BaseScene {
public:
	ColisonScene(lny::EngineWindow  localWindow,lny::LannyEngine * engine,lny::MediaManager * media, lny::DEFAULT_MANAGER* w):BaseScene(localWindow, engine,media,w){}

	float dt;
	void init() {

		registerInputEvent(lny::eventType::keyEvent, sf::Keyboard::Escape, END);
		registerInputEvent(lny::eventType::keyEvent, sf::Keyboard::W,      MOVE_UP);
		registerInputEvent(lny::eventType::keyEvent, sf::Keyboard::S,      MOVE_DOWN);
		registerInputEvent(lny::eventType::keyEvent, sf::Keyboard::A,      MOVE_LEFT);
		registerInputEvent(lny::eventType::keyEvent, sf::Keyboard::D,      MOVE_RIGHT);
		registerInputEvent(lny::eventType::keyEvent, sf::Keyboard::Num1,   CHANGE_SCENE);
		registerInputEvent(lny::eventType::keyEvent, sf::Keyboard::Num2,   GET_FPS);

		registerInputEvent(lny::eventType::mouseEvent, sf::Mouse::Left, COLIDE_CURSOR);
		globalMedia->globalTextures.loadTexture("box", "crate0_diffuse.png");
		globalMedia->globalTextures.loadTexture("pen", "pen.jpg");
		globalMedia->globalTextures.loadTexture("car", "car1_spr.png");

		lny::Entity rect = entityManager->addEntity();
		rect.getComponent<lny::CompShape>() = lny::CompShape({ 100,100 });
		rect.getComponent<lny::CompTransform>() = lny::CompTransform(lny::Vec2(10, 10),0);
		rect.getComponent<lny::CompBB>() = lny::CompBB({ 100,100 });

		for (int i = 0; i < 5; i++) {
			lny::Entity Two = entityManager->addEntity();
			Two.getComponent<lny::CompShape>() = lny::CompShape({ 100,100 });
			Two.getComponent<lny::CompTransform>() = lny::CompTransform(lny::Vec2(1 + (rand() % 1000), 1 + (rand() % 1000)), 0);
			Two.getComponent<lny::CompBB>() = lny::CompBB({ 100,100 });
		}
		
	
		
	}
	//colides bounding boxes using AABB
	void AABBmouseColide(lny::Vec2 mousePos) {
		for (auto& entityOne : entityManager->entities) {
			if (entityOne.hasComponent<lny::CompBB>() && entityOne.hasComponent<lny::CompTransform>()) {
				float rightMostX = entityOne.getComponent<lny::CompBB>().size.x + entityOne.getComponent<lny::CompTransform>().pos.x;
				float rightMostY = entityOne.getComponent<lny::CompBB>().size.y + entityOne.getComponent<lny::CompTransform>().pos.y;
				if ((mousePos.x > entityOne.getComponent<lny::CompTransform>().pos.x && mousePos.x < rightMostX) &&
					(mousePos.y > entityOne.getComponent<lny::CompTransform>().pos.y && mousePos.y < rightMostY)) {
					
				}
			}
		}
	}

	bool entityAABBCheck(lny::Entity One,lny::Entity Two) {
		float oneRightMostX = One.getComponent<lny::CompBB>().size.x + One.getComponent<lny::CompTransform>().pos.x;
		float oneRightMostY = One.getComponent<lny::CompBB>().size.y + One.getComponent<lny::CompTransform>().pos.y;

		float TwoRightMostX = Two.getComponent<lny::CompBB>().size.x + Two.getComponent<lny::CompTransform>().pos.x;
		float TwoRightMostY = Two.getComponent<lny::CompBB>().size.y + Two.getComponent<lny::CompTransform>().pos.y;


		if (((oneRightMostX < TwoRightMostX && oneRightMostX > Two.getComponent<lny::CompTransform>().pos.x) ||
			(One.getComponent<lny::CompTransform>().pos.x < TwoRightMostX && One.getComponent<lny::CompTransform>().pos.x > Two.getComponent<lny::CompTransform>().pos.x))&&
			((oneRightMostY < TwoRightMostY && oneRightMostY > Two.getComponent<lny::CompTransform>().pos.y) ||
			(One.getComponent<lny::CompTransform>().pos.y < TwoRightMostY && One.getComponent<lny::CompTransform>().pos.y > Two.getComponent<lny::CompTransform>().pos.y))) {
			return true;
		}
		return false;
	}
	void hitTest() {
		for (auto& entOne : entityManager->entities) {
			if (entOne.hasComponent<lny::CompBB>() && entOne.hasComponent<lny::CompTransform>()) {
				for (auto& entTwo : entityManager->entities) {
					if (entOne.getid() != entTwo.getid() && entTwo.hasComponent<lny::CompBB>() && entTwo.hasComponent<lny::CompTransform>()) {
						if (entityAABBCheck(entOne, entTwo)) {
							entOne.getComponent<lny::CompShape>().shape.setFillColor(sf::Color(255, 0, 0));
						}
					}
				}
			}
		}
	}

	void updatePos(float deltaT) {
		for (auto& entOne : entityManager->entities) {
			if (entOne.hasComponent<lny::CompTransform>()) {

				entOne.getComponent<lny::CompTransform>().pos.x += entOne.getComponent<lny::CompTransform>().xvel * deltaT;
				entOne.getComponent<lny::CompTransform>().pos.y += entOne.getComponent<lny::CompTransform>().yvel * deltaT;
			}
		}
	}
	void run_frameIndependant() {
		globalEngine->input();
		entityManager->sweepInactive();
		hitTest();
		render();
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	void run(float deltaT) {
		dt = deltaT;
		updatePos(deltaT);
	}
	void getFrameRate() {
		std::cout << "current frames per second: " << 1 / dt << "\n";

	}
	void reciveInput(lny::Event myEvent) {
		switch (myEvent.name) {
		case END:
			kill();
			break;
		case MOVE_RIGHT:
			if (myEvent.active) {
				entityManager->entities[0].getComponent<lny::CompTransform>().xvel = 150.f;
			}
			else {
				entityManager->entities[0].getComponent<lny::CompTransform>().xvel = 0;
			}
			break;
		case MOVE_LEFT:
			if (myEvent.active) {
				entityManager->entities[0].getComponent<lny::CompTransform>().xvel = -150.f;
			}
			else {
				entityManager->entities[0].getComponent<lny::CompTransform>().xvel = 0;
			}
			break;
		case MOVE_UP:
			if (myEvent.active) {
				entityManager->entities[0].getComponent<lny::CompTransform>().yvel = -150.f;
			}
			else {
				entityManager->entities[0].getComponent<lny::CompTransform>().yvel = 0;
			}
			break;
		case MOVE_DOWN:
			if (myEvent.active) {
				entityManager->entities[0].getComponent<lny::CompTransform>().yvel = 150.f;
			}
			else {
				entityManager->entities[0].getComponent<lny::CompTransform>().yvel = 0;
			}
			break;
		case CHANGE_SCENE:
			if (myEvent.active) {

				globalEngine->playScene("scene2");
			}
			break;
		case GET_FPS:
			if (!myEvent.active) {
				getFrameRate();
			}
			break;
		case COLIDE_CURSOR:
			std::cout << entityAABBCheck(entityManager->entities[0], entityManager->entities[1]);
			break;
		}
	}
};