#pragma once
#include <SFML/Graphics.hpp>
#include "Entity/EntityManager.hpp"
#include "Entity/ComponentManager.hpp"
#include "Media/MediaManager.hpp"
#include <iostream>
#include "Event.hpp"
namespace lny {
	enum eventType {
		keyEvent,
		mouseEvent
	};
	class LannyEngine;
	typedef std::shared_ptr<sf::RenderWindow> EngineWindow;
	typedef std::shared_ptr<lny::EntityManager> SceneEntityManager;
	/*
	* BaseScene class that is used both as an abstract class to derive specific scenes and as a default scene with no entities
	* classes derived from BaseScene can be used to initalize components of entities using init and have their behavior determined by run
	* 
	*/
	class BaseScene
	{
	protected:
		EngineWindow window;
		SceneEntityManager entityManager;
		//pointer back to the engine
		lny::LannyEngine* globalEngine;
		//pointer back to the media manager
		lny::MediaManager* globalMedia;
		
		bool isRunning = false;
		bool isPaused = false;
	public:
		//map holding keycode event id pairs
		std::map<int, int> keyEvents;
		std::map<int, int> mouseEvents;
		//constructor using shared ptr of the window and the engine
#ifdef COMPONENT_MANAGER
		BaseScene(EngineWindow localWindow, lny::LannyEngine* engine, lny::MediaManager* media, COMPONENT_MANAGER * components) :
			entityManager(new EntityManager(components)),
			globalEngine(engine),
			globalMedia(media),
			window(localWindow)
		{}
#else
		BaseScene(EngineWindow localWindow, lny::LannyEngine* engine, lny::MediaManager* media, DEFAULT_MANAGER * components) :
			entityManager(new EntityManager(components)),
			globalEngine(engine),
			globalMedia(media),
			window(localWindow)
		{}
#endif
		//renders all renderable Entites
		void render();

		//adds an event to the events map
		void registerInputEvent(enum eventType type,int key, int id);

		//kills the current scene loop and sets isRunning to false
		void kill();

		bool* isOn() {
			return &isRunning;
		}

		//initalizes the entities of a scene along with keyPresses and media. 
		virtual void init();
		
		//run function that is frame independant and 
		virtual void run_frameIndependant();

		//gets called by sceneLoop on each frame, used to determine entity behavior
		virtual void run(float deltaT);
		
		//does whatever event is sent in even
		virtual void reciveInput(lny::Event localEvent);
	};
}
