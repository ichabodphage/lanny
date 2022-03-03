#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Entity/Managers/EntityManager.hpp"
#include "../Entity/Managers/ComponentManager.hpp"
#include "../Media/MediaHub.hpp"
#include "../Input/Event.hpp"
#include "../Typedefs.hpp"
#include "../Input/InputManager.hpp"
#include "RenderSystem/RenderSystem.hpp"
namespace lny {
	enum eventType {
		keyEvent,
		mouseEvent
	};
	class LannyEngine;
	typedef std::shared_ptr<sf::RenderWindow> EngineWindow;
	/*
	* BaseScene class that is used both as an abstract class to
	*	derive specific scenes and as a default scene with no entities
	* classes derived from BaseScene can be used to initalize components of entities using init and have their behavior determined by run
	* 
	*/
	class BaseScene
	{
	protected:
		EngineWindow window;
		//scenes entity manager
		lny::EntityManager entityManager;
		//pointer back to the engine
		lny::LannyEngine* globalEngine;
		//pointer back to the media manager
		lny::GLOBAL_MEDIA* globalMedia;

		//scenes renderer
		lny::RenderSystem localRenderer;
		
		bool isRunning = false;
		bool isPaused = false;
	public:
		//scenes input manager
		lny::InputManager sceneInput;

		//constructor using shared ptr of the window and the engine
		BaseScene(EngineWindow localWindow, lny::LannyEngine* engine, lny::GLOBAL_MEDIA* media, ComponentMgr * components) :
			entityManager(components),
			globalEngine(engine),
			globalMedia(media),
			window(localWindow),
			localRenderer(localWindow,&entityManager,components->getEntityLimit()),
			sceneInput(){}

		//renders all renderable Entites
		virtual void render();
	

		//kills the current scene loop and sets isRunning to false
		void kill();

		//returns if the scene is active or not
		bool* isOn() {
			return &isRunning;
		}

		//initalizes the entities of a scene along with keyPresses and media. 
		virtual void init();
		
		//run function that is frame independant and 
		virtual void run_frameIndependant();

		//gets called by sceneLoop on each frame, used to determine entity behavior
		virtual void run(float deltaT);
		
	};
}

