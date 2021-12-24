#pragma once
#include <SFML/Graphics.hpp>
#include "engine/EntityManager.hpp"
enum EntType {
	REGULAR = 0
};
typedef std::shared_ptr<sf::RenderWindow> AppWindow;
typedef std::shared_ptr<lny::EntityManager> AppEntityManager;
//App class handles the window and the entity manager
class App
{
private:
	AppWindow window;
	AppEntityManager entityManager;
	bool isRunning = false;
	bool isPaused = false;
public:
	App(sf::VideoMode video, std::string name) :
		window(new sf::RenderWindow(video, name)),
		entityManager(new lny::EntityManager()) {};
	//sets isRunning to true and begins the gameLoop
	void init();

	//runs all the eventHandlers until isRunning is false
	void run();

	//event handler
	void handleEvents();

	//adds a red square
	void addSquare();
	
	void render();
};

