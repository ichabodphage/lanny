#pragma once
#include "../engine/Scene/BaseScene.hpp"
#include "../engine/LannyEngine.hpp"
#include "../engine/Entity/Entity.hpp"
#include <random>
#include <iostream>
#include <thread>
#include <chrono>


/*
* ColisonScene is a scene meant to test the engines input system
*/
class ColisonScene: public lny::BaseScene {
public:
	ColisonScene(lny::EngineWindow  localWindow,lny::LannyEngine * engine,lny::GLOBAL_MEDIA* media, lny::DEFAULT_MANAGER* w):BaseScene(localWindow, engine,media,w){}

	//time change variable
	float dt = 0.f;

	void init() {
		//left movement listener
		sceneInput.listen(lny::Key,sf::Keyboard::Key::Left,
		[this](lny::Event keyEvent){
			if(keyEvent.active){
				this->entityManager->entities[0]
				.getComponent<lny::CompMovement>().velocity.x = -100;
			}else{
				this->entityManager->entities[0]
				.getComponent<lny::CompMovement>().velocity.x = 0;
			}
		});

		//right movement listener
		sceneInput.listen(lny::Key,sf::Keyboard::Key::Right,
		[this](lny::Event keyEvent){
			if(keyEvent.active){
				this->entityManager->entities[0]
				.getComponent<lny::CompMovement>().velocity.x = 100;
			}else{
				this->entityManager->entities[0]
				.getComponent<lny::CompMovement>().velocity.x = 0;
			}
		});
		//up movement listener
		sceneInput.listen(lny::Key,sf::Keyboard::Key::Up,
		[this](lny::Event keyEvent){
			if(keyEvent.active){
				this->entityManager->entities[0]
				.getComponent<lny::CompMovement>().velocity.y = -100;
			}else{
				this->entityManager->entities[0]
				.getComponent<lny::CompMovement>().velocity.y = 0;
			}
		});
		
		//down movement listener
		sceneInput.listen(lny::Key,sf::Keyboard::Key::Down,
		[this](lny::Event keyEvent){
			if(keyEvent.active){
				this->entityManager->entities[0]
				.getComponent<lny::CompMovement>().velocity.y = 100;
			}else{
				this->entityManager->entities[0]
				.getComponent<lny::CompMovement>().velocity.y = 0;
			}
		});
		
		//left movement listener
		sceneInput.listen(lny::Mouse, sf::Mouse::Left, 
		[this](lny::Event keyEvent) {
			if(keyEvent.active)
				this->getFrameRate();
		});
		sceneInput.listen(lny::Key, sf::Keyboard::Num1, 
		[this](lny::Event keyEvent) {
			if(keyEvent.active)
				globalEngine->playScene("scene2");
		});
		//set asset manager's folders
		globalMedia->setFolder<lny::TextureManager>("TextureAssets");
		globalMedia->setFolder<lny::MusicManager>("MusicAssets");

		//load necessary textures
		globalMedia->get<lny::TextureManager>()
		.loadTexture("box", "crate0_diffuse.png");
		globalMedia->get<lny::TextureManager>()
		.loadTexture("pen", "pen.jpg");
		globalMedia->get<lny::TextureManager>()
		.loadTexture("car", "car1_spr.png");

		//add player entity
		lny::Entity rect = entityManager->addEntity();
		
		rect.getComponent<lny::CompShape>() = 
		lny::CompShape({ 50,50 });
		
		rect.getComponent<lny::CompTransform>() = 
		lny::CompTransform(lny::Vec2(10, 10),0);
		
		rect.getComponent<lny::CompBB>() = 
		lny::CompBB({ 50,50 });
		
		rect.getComponent<lny::CompMovement>() = 
		lny::CompMovement({ 0,0 });

		//add nonplayer colision entities
		for (int i = 0; i < 10; i++) {
			lny::Entity Two = entityManager->addEntity();
			
			Two.getComponent<lny::CompShape>() = 
			lny::CompShape({ 50,50 });
			
			Two.getComponent<lny::CompTransform>() = 
			lny::CompTransform(lny::Vec2(1 + (rand() % 440), 1 + (rand() % 440)), 0);
			
			Two.getComponent<lny::CompBB>() = 
			lny::CompBB({ 50,50 });
		}
		
	
		
	}
	
	//unused function that checks for an AABB colision with the mouse cursor
	void AABBmouseColide(lny::Vec2 mousePos) {
		for (auto& entityOne : entityManager->entities) {
			if (entityOne.hasComponent<lny::CompBB>() &&
				entityOne.hasComponent<lny::CompTransform>()) {
				
				float rightMostX = 
				entityOne.getComponent<lny::CompBB>().size.x +
				entityOne.getComponent<lny::CompTransform>().pos.x;
				
				float rightMostY = 
				entityOne.getComponent<lny::CompBB>().size.y + 
				entityOne.getComponent<lny::CompTransform>().pos.y;
				
				if ((mousePos.x > entityOne.getComponent<lny::CompTransform>().pos.x &&
					mousePos.x < rightMostX) &&
					(mousePos.y > entityOne.getComponent<lny::CompTransform>().pos.y &&
					mousePos.y < rightMostY)) {
					
				}
			}
		}
	}

	//function that does an AABB check on 2 entities
	bool entityAABBCheck(lny::Entity One,lny::Entity Two) {
		//get rightmost x and y cordinates of both entities
		float oneRightMostX = 
		One.getComponent<lny::CompBB>().size.x +
		One.getComponent<lny::CompTransform>().pos.x;
		
		float oneRightMostY = 
		One.getComponent<lny::CompBB>().size.y +
		One.getComponent<lny::CompTransform>().pos.y;

		float TwoRightMostX = 
		Two.getComponent<lny::CompBB>().size.x +
		Two.getComponent<lny::CompTransform>().pos.x;
		
		float TwoRightMostY = 
		Two.getComponent<lny::CompBB>().size.y +
		Two.getComponent<lny::CompTransform>().pos.y;

		//return the result of the bounding box check
		return((oneRightMostX < TwoRightMostX&& oneRightMostX >
			Two.getComponent<lny::CompTransform>().pos.x) ||
			(One.getComponent<lny::CompTransform>().pos.x < TwoRightMostX&&
			One.getComponent<lny::CompTransform>().pos.x >
			Two.getComponent<lny::CompTransform>().pos.x)) &&
			((oneRightMostY < TwoRightMostY&& oneRightMostY >
			Two.getComponent<lny::CompTransform>().pos.y) ||
			(One.getComponent<lny::CompTransform>().pos.y < TwoRightMostY&&
			One.getComponent<lny::CompTransform>().pos.y >
			Two.getComponent<lny::CompTransform>().pos.y));
	}

	//scene system that checks for bounding box colisions between all entities
	void hitTest() {
		for (auto& entOne : entityManager->entities) {
			if (entOne.hasComponent<lny::CompBB>() &&
				entOne.hasComponent<lny::CompTransform>()) {
				
				for (auto& entTwo : entityManager->entities) {
					if (entOne.getid() != entTwo.getid() &&
						entTwo.hasComponent<lny::CompBB>() &&
						entTwo.hasComponent<lny::CompTransform>() &&
						entityAABBCheck(entOne, entTwo)) 
					{	
						entOne.getComponent<lny::CompShape>()
						.shape.setFillColor(sf::Color(255, 0, 0));	
					}
				}
			}
		}
	}
	//scene systems that sets all the entities to a white color
	void recolor(){
		for (auto& entOne : entityManager->entities) {
			if (entOne.hasComponent<lny::CompShape>()) {
				entOne.getComponent<lny::CompShape>()
				.shape.setFillColor(sf::Color(255,255,255));
			}
		}
	}
	//scene system that updates each entities posiiton using its velocity
	void updatePos(float deltaT) {
		for (auto& entOne : entityManager->entities) {
			if (entOne.hasComponent<lny::CompTransform>() &&
				entOne.hasComponent<lny::CompMovement>()) {
				
				entOne.getComponent<lny::CompTransform>().pos.x +=
				entOne.getComponent<lny::CompMovement>().velocity.x * deltaT;
				
				entOne.getComponent<lny::CompTransform>().pos.y +=
				entOne.getComponent<lny::CompMovement>().velocity.y * deltaT;
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
	//method that prints the scenes current framerate
	void getFrameRate() {
		std::cout << "framerate: " << 1 / dt << "\n";
	}

};