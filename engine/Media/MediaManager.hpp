#pragma once
#include "Audio/MusicManager.hpp"
#include "Texture/TextureManager.hpp"

namespace lny {
	/*
	* media manager struct used for holding all of the engines 
	* media managers. used to make engine media easier to maintain
	*/
	struct MediaManager {
		//engine texture manager
		lny::TextureManager globalTextures;
		//engine music manager
		lny::MusicManager globalMusic;
		
		//constructor using texture path and music path
		MediaManager(std::string pathOne, std::string pathTwo):
			globalTextures(pathOne),
			globalMusic(pathTwo) {};
	};
}