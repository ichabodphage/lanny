#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <map>
#include <memory>
/*
* music mixer class to handle playing and loading of music
*/
namespace lny {
	class MusicManager
	{
	private:
		//map holding track name keys and file name pair values
		std::map<std::string, std::string> music;

		//path to music folder
		std::string musicFolder;

		//current track being played
		sf::Music currentTrack;
	public:
		MusicManager(std::string path) : musicFolder(path) {};

		//adds a track to the mixer
		void loadTrack(std::string name, std::string file);

		//plays a track in the music map
		void playTrack(std::string name);

		//pauses the current track
		void pauseCurrentTrack();

		//stops the current track from playing
		void stopCurrentTrack();
	};
}
