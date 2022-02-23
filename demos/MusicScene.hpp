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
	float dt = 0.f;
	void init() {


		globalMedia->get<lny::MusicManager>().loadTrack("songOne", "Orbital_Colossus.wav");


	}
	void run(float deltaT) {

		dt = deltaT;

	}

	void getFrameRate() {
		std::cout << "current frames per second: " << 1 / dt << "\n";

	}

	
};