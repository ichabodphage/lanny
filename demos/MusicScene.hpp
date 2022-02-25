#pragma once

#include "../engine/Scene/BaseScene.hpp"
#include "../engine/LannyEngine.hpp"
#include "../engine/Entity/Entity.hpp"
#include <random>
#include <chrono>
#include <iostream>
#include <thread>

/*
* music scene is a scene meant to test the engines audio system
*
*/
class MusicScene : public lny::BaseScene {
public:
	MusicScene(lny::EngineWindow  localWindow, lny::LannyEngine* engine, lny::GLOBAL_MEDIA* media, lny::ComponentMgr* w) :BaseScene(localWindow, engine, media, w) {}

	float dt = 0.f;

	void init() {
		
		//input listner that returns to the first scene
		sceneInput.listen(lny::Key, sf::Keyboard::Num1, 
		[this](lny::Event keyEvent) {
			if(keyEvent.active)
				globalEngine->playScene("scene1");
		});
		
		//input listner that plays the scenes song
		sceneInput.listen(lny::Key, sf::Keyboard::Num2, 
		[this](lny::Event keyEvent) {
			if(keyEvent.active)
				this->globalMedia->get<lny::MusicManager>()
				.playTrack("songOne");
		});
		
		//load a song into the music manager
		globalMedia->get<lny::MusicManager>()
		.loadTrack("songOne", "Orbital_Colossus.wav");


	}
	void run(float deltaT) {

		dt = deltaT;

	}

	void getFrameRate() {
		std::cout << "current frames per second: " << 1 / dt << "\n";

	}

	
};