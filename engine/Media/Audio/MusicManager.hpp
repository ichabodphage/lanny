#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <map>
#include <memory>
#include "../BaseMediaManager.hpp"
/*
* music mixer class to handle playing and loading of music
*/
namespace lny {
	class MusicManager : public lny::BaseMediaManager<std::string>
	{
	private:

		//path to the current song
		std::string currentTrackPath;
		
		//current track being played
		sf::Music currentTrack;
	public:
		MusicManager() : lny::BaseMediaManager<std::string>() {};

		//adds a track to the mixer
		void loadTrack(std::string name, std::string file);

		//plays a track in the music map
		void playTrack(std::string name, bool repeat = false);

		//pauses the current track
		void pauseCurrentTrack();

		//stops the current track from playing
		void stopCurrentTrack();
	};
}
