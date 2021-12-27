#pragma once
#include <SFML/Graphics.hpp>
#include "Entity/EntityManager.hpp"
#include <iostream>
#include "Event.hpp"
namespace lny {
	class LannyEngine;
	typedef std::shared_ptr<sf::RenderWindow> EngineWindow;
	typedef std::shared_ptr<lny::EntityManager> SceneEntityManager;
	class BaseScene
	{
	protected:
		EngineWindow window;
		SceneEntityManager entityManager;
		//engine is initalized on heap so raw pointer is acceptable
		lny::LannyEngine* localEngine;
		bool isRunning = false;
		bool isPaused = false;
	public:
		std::map<int, int> events;
		BaseScene(EngineWindow localWindow, lny::LannyEngine* engine) :
			entityManager(new EntityManager()),
			localEngine(engine),
			window(localWindow)
		{}
		//loop that runs while isRunning, runs 
		void sceneLoop();
		//renders all renderable Entites
		void render();

		//adds an event to the events map
		void registerKeyEvent(int key, int id);
		
		//kills the current scene loop and sets isRunning to false
		void kill();

		//starts the main level loop and sets isRunning to true
		void start();

		//initalizes the scene, will be different amoung children classes
		virtual void init();
		
		//gets called by sceneLoop on each frame
		virtual void run();
		
		//does whatever event is sent in even
		virtual void reciveEvent(lny::Event localEvent);
	};
}

