#include "MusicManager.hpp"
using namespace lny;

void MusicManager::loadTrack(std::string name, std::string path) {
	try {
		music.at(name);
		std::cout << "song " << name << " allready loaded\n";
	}
	catch (std::exception e) {
		music[name] = musicFolder + "\\" + path;
		std::cout << "song " << name << " successfully loaded from: " << musicFolder << "\\" << path << "\n";
	}
}

void MusicManager::playTrack(std::string name) {
	try {
		std::string path = music.at(name);
		if (currentTrack.getStatus() != sf::Music::Status::Paused && currentTrack.openFromFile(path)) {
			currentTrack.openFromFile(path);
			currentTrack.play();
		}
		else if (currentTrack.getStatus() == sf::Music::Status::Paused) {
			currentTrack.play();
		}
		else {
			std::cout << "error, music file: " << path << " is not a valid path.\n";
		}
	}catch (std::exception e) {
		std::cout << "error, music named: " << name << " is not currently loaded\n";
	}
}

void MusicManager::pauseCurrentTrack() {
	if (currentTrack.getStatus() == sf::Music::Status::Playing) {
		currentTrack.pause();
	}

}