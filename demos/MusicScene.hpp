#pragma once

#include "../engine/Scene/BaseScene.hpp"
#include "../engine/LannyEngine.hpp"
#include "../engine/Entity/Entity.hpp"

#include <random>
#include <chrono>
#include <iostream>
#include <thread>
class MusicScene : public lny::BaseScene {
public:
	MusicScene(lny::EngineWindow  localWindow, lny::LannyEngine* engine, lny::GLOBAL_MEDIA* media, lny::ComponentMgr* w) :BaseScene(localWindow, engine, media, w) {}
	float dt;
	void init() {

		registerInputEvent(lny::eventType::keyEvent, sf::Keyboard::Escape, END);
		registerInputEvent(lny::eventType::keyEvent, sf::Keyboard::Num1,   CHANGE_SCENE);
		registerInputEvent(lny::eventType::keyEvent, sf::Keyboard::Num2,   GET_FPS);
		registerInputEvent(lny::eventType::keyEvent, sf::Keyboard::Num3,   PLAY_SONG);
		registerInputEvent(lny::eventType::keyEvent, sf::Keyboard::Num4,   PAUSE_SONG);


		globalMedia->get<lny::MusicManager>().loadTrack("songOne", "Orbital_Colossus.wav");



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

				globalEngine->playScene("scene1");
			}
			break;
		case GET_FPS:
			if (!myEvent.active) {
				getFrameRate();
			}
			break;
		case PLAY_SONG:
			if (myEvent.active) {
				globalMedia->get<lny::MusicManager>().playTrack("songOne");
			}
			break;
		case PAUSE_SONG:
			if (myEvent.active) {
				globalMedia->get<lny::MusicManager>().pauseCurrentTrack();
			}
			break;
		}
	}
};