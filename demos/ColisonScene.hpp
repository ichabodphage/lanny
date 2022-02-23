#pragma once
#include "../engine/Scene/BaseScene.hpp"
#include "../engine/LannyEngine.hpp"
#include "../engine/Entity/Entity.hpp"
#include <random>
#include <iostream>
#include <thread>
#include <chrono>

class ColisonScene: public lny::BaseScene {
public:
	ColisonScene(lny::EngineWindow  localWindow,lny::LannyEngine * engine,lny::GLOBAL_MEDIA* media, lny::DEFAULT_MANAGER* w):BaseScene(localWindow, engine,media,w),localBatch(w->getEntityLimit()) {}
	lny::RenderBatch localBatch;

	float dt = 0.f;
	void init() {
		sceneInput.listen(sf::Keyboard::Key::Left,[](lny::EntityManager* entManager){
			entManager->entities[0].getComponent<lny::CompTransform>().pos.x -= 10;
		});

		
		sceneInput.listen(sf::Keyboard::Key::Right,[](lny::EntityManager* entManager){
			
		});
		
		globalMedia->setFolder<lny::TextureManager>("TextureAssets");
		globalMedia->setFolder<lny::MusicManager>("MusicAssets");
		globalMedia->get<lny::TextureManager>().loadTexture("box", "crate0_diffuse.png");
		globalMedia->get<lny::TextureManager>().loadTexture("pen", "pen.jpg");
		globalMedia->get<lny::TextureManager>().loadTexture("car", "car1_spr.png");
	
		lny::Entity rect = entityManager->addEntity();
		rect.getComponent<lny::CompShape>() = lny::CompShape({ 50,50 });
		rect.getComponent<lny::CompTransform>() = lny::CompTransform(lny::Vec2(10, 10),0);
		rect.getComponent<lny::CompBB>() = lny::CompBB({ 50,50 });
		rect.getComponent<lny::CompMovement>() = lny::CompMovement({ 0,0 });
		for (int i = 0; i < 10; i++) {
			lny::Entity Two = entityManager->addEntity();
			Two.getComponent<lny::CompShape>() = lny::CompShape({ 50,50 });
			Two.getComponent<lny::CompTransform>() = lny::CompTransform(lny::Vec2(1 + (rand() % 440), 1 + (rand() % 440)), 0);
			Two.getComponent<lny::CompBB>() = lny::CompBB({ 50,50 });
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
	void recolor(){
		for (auto& entOne : entityManager->entities) {
			if (entOne.hasComponent<lny::CompShape>()) {

				entOne.getComponent<lny::CompShape>().shape.setFillColor(sf::Color(255,255,255));
			}
		}
	}
	void updatePos(float deltaT) {
		for (auto& entOne : entityManager->entities) {
			if (entOne.hasComponent<lny::CompTransform>() && entOne.hasComponent<lny::CompMovement>()) {
				entOne.getComponent<lny::CompTransform>().pos.x += entOne.getComponent<lny::CompMovement>().velocity.x * deltaT;
				entOne.getComponent<lny::CompTransform>().pos.y += entOne.getComponent<lny::CompMovement>().velocity.y * deltaT;
			}
		}
	}
	void run_frameIndependant() {
		entityManager->sweepInactive();
		recolor();
		hitTest();
		localRenderer.render();
		std::this_thread::sleep_for(std::chrono::milliseconds(4));
	}
	void run(float deltaT) {
		dt = deltaT;
		updatePos(deltaT);
	}
	void getFrameRate() {


	}

};