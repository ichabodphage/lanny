#include "MusicManager.hpp"
using namespace lny;

void MusicManager::loadTrack(std::string name, std::string path) {
	try {
		//check if song name is allready loaded
		music.at(name);
		std::cout << "song " << name << " allready loaded\n";
	}
	catch (std::exception e) {
		//add the file path to the music map if the file is not loaded
		sf::Music checkPath;
		if(checkPath.openFromFile(assetFolder + "/" + path)){
			//load the music path if it is a valid path
			music[name] = assetFolder + "/" + path;
			std::cout << "song " << name << " successfully loaded from: " << assetFolder << "/" << path << "\n";
		}else{
			//log an error if the music file does not successfully load
			std::cout << "error, music file: " << assetFolder + "/" + path << " is not a valid path\n";
		}
	}
}

void MusicManager::playTrack(std::string name, bool repeat) {
	try {
		std::string path = music.at(name);

		if (currentTrackPath != path && currentTrack.openFromFile(path)) {
			//play the music from path if the path is not the same as the path of the current file
			currentTrackPath = path;
			currentTrack.openFromFile(path);
			currentTrack.play();
			//loop the track if repeat is true
			currentTrack.setLoop(repeat);
		}
		else if (currentTrack.getStatus() == sf::Music::Status::Paused || currentTrack.getStatus() == sf::Music::Status::Stopped) {
			//resume playing the track if the current track is paused
			currentTrack.play();
		}
		
	}catch (std::exception e) {
		std::cout << "error, music named: " << name << " is not defined\n";
	}
}

void MusicManager::pauseCurrentTrack() {
	if (currentTrack.getStatus() == sf::Music::Status::Playing) {
		currentTrack.pause();
	}

}