#include "LannyEngine.hpp"
#include <random>
#include <iostream>
using namespace lny;

void LannyEngine::insertScene(std::string sceneName, ScenePtr scene) {
	scenes[sceneName] = scene;
}

void LannyEngine::loadScene(std::string sceneName) {
	auto localScene = scenes.at(sceneName);
	localScene->init();
}

