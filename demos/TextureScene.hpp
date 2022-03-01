#pragma once
#include "../engine/Scene/BaseScene.hpp"
#include "../engine/LannyEngine.hpp"
#include "../engine/Entity/Entity.hpp"
#include <random>
#include <chrono>
#include <thread>

/*
* TextureScene is a scene meant to test the engines texture loading system
*
*/
class TextureScene : public lny::BaseScene {
public:
	TextureScene(lny::EngineWindow localWindow, lny::LannyEngine* engine, lny::GLOBAL_MEDIA* media,lny::ComponentMgr * w) :BaseScene(localWindow, engine, media,w) {}

	float dt = 0.f;
	void init() {
		
		//event listener for loading next scene
		sceneInput.listen(lny::Key, sf::Keyboard::Num1, 
		[this](lny::Event keyEvent) {
			if(keyEvent.active)
				globalEngine->playScene("scene3");
		});
		
		//framerate event listener
		sceneInput.listen(lny::Mouse, sf::Mouse::Left, 
		[this](lny::Event keyEvent) {
			if(keyEvent.active)
				this->getFrameRate();
		});

		//loop that adds box entities
		for (int i = 0; i < 100; i+=10) {
			lny::Entity rect = entityManager.addEntity();
			
			rect.getComponent<lny::CompShape>() = 
			lny::CompShape({ 50,50 },
			globalMedia->get<lny::TextureManager>().getTexture("box"));
			
			rect.getComponent<lny::CompShape>()
			.shape.setFillColor(sf::Color(255 - (i*1.5), 255, 255));
			
			rect.getComponent<lny::CompTransform>() =
			lny::CompTransform(lny::Vec2(10, 10 +i*5), 0);

		}
	
		//loop that adds pen entities
		for (int j = 0; j < 100; j += 10) {
			lny::Entity rect2 = entityManager.addEntity();
			rect2.getComponent<lny::CompShape>() = 
			lny::CompShape({ 50,50 },
			globalMedia->get<lny::TextureManager>().getTexture("pen"));
			
			rect2.getComponent<lny::CompShape>()
			.shape.setFillColor(sf::Color(255, 255 - j, 255));
			rect2.getComponent<lny::CompTransform>() =
			lny::CompTransform(lny::Vec2(120, 10 + j * 5), 0);
		}

		//loop that adds car entities
		for (int j = 0; j < 100; j += 10) {
			lny::Entity rect2 = entityManager.addEntity();
			
			rect2.getComponent<lny::CompShape>() = 
			lny::CompShape({ 100,50 },
			globalMedia->get<lny::TextureManager>().getTexture("car"));
			
			rect2.getComponent<lny::CompShape>()
			.shape.setFillColor(sf::Color(255, 255, 255 - j));
			
			rect2.getComponent<lny::CompTransform>() =
			lny::CompTransform(lny::Vec2(220, 10 + j * 5), 0);
		}

	
	}
	void run(float deltaT) {
		dt = deltaT;

	}
	void getFrameRate() {
		std::cout << "current frames per second: " << 1 / dt << "\n";
	}
	
};