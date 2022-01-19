#pragma once
#include "../engine/BaseScene.hpp"
#include "../engine/LannyEngine.hpp"
#include "../engine/Entity/Entity.hpp"
#include <random>

enum eventIDs {
	END,
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT,
	CHANGE_SCENE
};
class ColisonScene: public lny::BaseScene {
public:
	ColisonScene(lny::EngineWindow  localWindow,lny::LannyEngine * engine,lny::MediaManager * media, lny::DEFAULT_MANAGER* w):BaseScene(localWindow, engine,media,w){}

	lny::Entity rect = entityManager->addEntity();
	void init() {
		registerKeyEvent(sf::Keyboard::Escape, END);
		registerKeyEvent(sf::Keyboard::W, MOVE_UP);
		registerKeyEvent(sf::Keyboard::S, MOVE_DOWN);
		registerKeyEvent(sf::Keyboard::A, MOVE_LEFT);
		registerKeyEvent(sf::Keyboard::D, MOVE_RIGHT);
		registerKeyEvent(sf::Keyboard::Num1, CHANGE_SCENE);
		
		rect.getComponent<lny::CompShape>() = lny::CompShape({ 100,100 });
		rect.getComponent<lny::CompTransform>() = lny::CompTransform(lny::Vec2(10, 10),0);
		rect.getComponent<lny::CompBB>() = lny::CompBB({ 100,100 });


		lny::Entity Two = entityManager->addEntity();
		Two.getComponent<lny::CompShape>() = lny::CompShape({ 100,100 });
		Two.getComponent<lny::CompTransform>() = lny::CompTransform(lny::Vec2(200, 100), 0);
		Two.getComponent<lny::CompBB>() = lny::CompBB({ 100,100 });
		std::cout << entityManager->entities.size();
		start();
	}
	//colides bounding boxes using AABB
	void AABBcolide() {
		for (auto& entityOne : entityManager->entities) {
			if (entityOne.hasComponent<lny::CompBB>()) {
				for (auto& entityTwo : entityManager->entities) {
					if (entityTwo.hasComponent<lny::CompBB>()) {
						//skip if entityOne is equal to entityTwo
						if (entityTwo.getid() == entityOne.getid()) {
							continue;
						}
						//entity One position
						auto posOne = entityOne.getComponent<lny::CompTransform>();
						auto boxOne = entityOne.getComponent<lny::CompBB>();
						float OneMaxX = posOne.pos.x + boxOne.size.x;
						float OneMaxY = posOne.pos.y + boxOne.size.y;
						//entityTwo position
						auto posTwo = entityTwo.getComponent<lny::CompTransform>();
						auto boxTwo = entityTwo.getComponent<lny::CompBB>();
						float TwoMaxX = posTwo.pos.x + boxTwo.size.x;
						float TwoMaxY = posTwo.pos.y + boxTwo.size.y;
					
						if ((posOne.pos.x < TwoMaxX && OneMaxX >posTwo.pos.x) &&
							(posOne.pos.y < TwoMaxY && OneMaxY >posTwo.pos.y)){
							entityOne.getComponent<lny::CompShape>().shape.setFillColor(sf::Color(255, 0, 0));
						}
						else {
							entityOne.getComponent<lny::CompShape>().shape.setFillColor(sf::Color(255, 255, 255));
						}
					}
				}
			}
		}
	}
	void run() {
		globalEngine->input();
		AABBcolide();
		render();
		
	}

	void reciveEvent(lny::Event myEvent) {
		switch (myEvent.name) {
		case END:
			kill();
			break;
		case MOVE_RIGHT:
			if (myEvent.active)
				rect.getComponent<lny::CompTransform>().pos.x += 2.5f;
			break;
		case MOVE_LEFT:
			if(myEvent.active)
				rect.getComponent<lny::CompTransform>().pos.x -= 2.5f;
			break;
		case MOVE_UP:
			if (myEvent.active)
				rect.getComponent<lny::CompTransform>().pos.y -= 2.5f;
			break;
		case MOVE_DOWN:
			if (myEvent.active)
				rect.getComponent<lny::CompTransform>().pos.y += 2.5f;
			break;
		case CHANGE_SCENE:
			kill();
			globalEngine->loadScene("scene2");
			break;
		}
	}
};