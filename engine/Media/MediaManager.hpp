#pragma once
#include "MusicManager.hpp"
#include "TextureManager.hpp"

namespace lny {
	struct MediaManager {
		lny::TextureManager globalTextures;
		lny::MusicManager globalMusic;
		MediaManager(std::string pathOne, std::string pathTwo):
			globalTextures(pathOne),
			globalMusic(pathTwo) {};
	};
}