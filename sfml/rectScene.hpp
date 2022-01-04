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
	END,
	INSERT_RECT,
	RECOLOR_RECT
};
class RectScene : public lny::BaseScene {
public:
	RectScene(lny::EngineWindow localWindow,lny::LannyEngine * engine,lny::MediaManager * media):BaseScene(localWindow, engine,media){}


	void init() {
		globalMedia->insertTexture("crate0_diffuse.png");
		//register key events
		registerKeyEvent(sf::Keyboard::Escape,END);
		registerKeyEvent(sf::Keyboard::Q, INSERT_RECT);
		registerKeyEvent(sf::Keyboard::W, RECOLOR_RECT);
		initRectangle({ 10,10 }, { 200,100 });
		//start game loop
		start();
	}
	void changeColor(){

		for (auto& entity : entityManager->entities) {
			for (int i = 0; i < entity->cShape->verticies.getVertexCount(); i++){
				entity->cShape->verticies[i].color.r = randomFloat(0, 255);
				entity->cShape->verticies[i].color.g = randomFloat(0, 255);
				entity->cShape->verticies[i].color.b = randomFloat(0, 255);
				
			}
		}
		
	}
	void rotateRandom() {
		if (globalEngine->getCurrentFrame() % 60 == 0) {
			for (auto& entity : entityManager->entities) {
				entity->cPosition->rotation += 1.f;
			}
		}
	}
	void sweep() {
		if (entityManager->entities.size() > 100) {
			for (int i = 0; i < 10; i++) {
				entityManager->entities[i]->disable();
			}
		}
		entityManager->update();
	}
	void initRectangle(lny::Vec2 pos, lny::Vec2 size) {
		auto rect = entityManager->insertEntity(RECT);
		rect->cPosition = std::make_shared<lny::CompTransform>(pos, randomFloat(-180, 180));
		rect->cShape = std::make_shared<lny::CompShape>(sf::Quads,4,size);
		for (int i = 0; i < rect->cShape->verticies.getVertexCount(); i++) {
			
			rect->cShape->verticies[i].color.r = randomFloat(0, 255);
			rect->cShape->verticies[i].color.g = randomFloat(0, 255);
			rect->cShape->verticies[i].color.b = randomFloat(0, 255);
			
		}

	}

	void run() {
		globalEngine->input();
		render();
		rotateRandom();
		sweep();

	}

	void reciveEvent(lny::Event myEvent) {
		switch (myEvent.name) { //keyboard input handler
		case END:
			kill();
			break;
		case INSERT_RECT:
			initRectangle({ randomFloat(0, 1280) ,randomFloat(0, 720) }, {randomFloat(0,400),randomFloat(0,400) });
			break;
		case RECOLOR_RECT:
			changeColor();
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