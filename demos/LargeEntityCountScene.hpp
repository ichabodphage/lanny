 #pragma once
#include "../engine/Scene/BaseScene.hpp"
#include "../engine/LannyEngine.hpp"
#include "../engine/Entity/Entity.hpp"
#include <random>
#include <chrono>
#include <iostream>

/*
* LargeEntityCountScene is a scene created to test the preformance of the
* engines renderer
*
*/
class LargeEntityCountScene : public lny::BaseScene {
public:
	LargeEntityCountScene(lny::EngineWindow  localWindow, lny::LannyEngine* engine, lny::GLOBAL_MEDIA* media, lny::ComponentMgr* w) :BaseScene(localWindow, engine, media, w){}
	
	float dt = 0.f;

	void init() {
		//next scene event listener
		sceneInput.listen(lny::Key, sf::Keyboard::Num1, 
		[this](lny::Event keyEvent) {
			if(keyEvent.active)
				globalEngine->playScene("scene4");
		});
		
		//framerate event listener
		sceneInput.listen(lny::Mouse, sf::Mouse::Left, 
		[this](lny::Event keyEvent) {
			if(keyEvent.active)
				this->getFrameRate();
		});
		
		//loop that inserts aproximately 10,000 entities into the scene 
		for (int i = 0; i < 100; i += 1) {
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < 10; k++) {
					lny::Entity rect = entityManager.addEntity();
					
					rect.getComponent<lny::CompShape>() =
					lny::CompShape(lny::Vec2(50,50));
					
					rect.getComponent<lny::CompShape>().shape
					.setFillColor(sf::Color(255, (rand() %255)+1, 255, (rand() % 255) + 1));
					
					rect.getComponent<lny::CompTransform>() =
					lny::CompTransform(lny::Vec2(10 + j*50 , 10 + k * 50), 0);
					
				}
			}
		}
		
	}
	void run_frameIndependant(){
		localRenderer.render();
	}
	void run(float deltaT) {

		dt = deltaT;
		
	}
	
	void getFrameRate() {
		std::cout << "current frames per second: " << 1 / dt << "\n";
	}

	
};