#pragma once
#include <SFML/Graphics.hpp>
#include "EntityManager.hpp"
typedef std::shared_ptr<sf::RenderWindow> EngineWindow;
typedef std::shared_ptr<lny::EntityManager> SceneEntityManager;
namespace lny {
	class BaseScene
	{
	protected:
		EngineWindow window;
		SceneEntityManager entityManager;
		bool isRunning = false;
		bool isPaused = false;
	public:
		BaseScene(EngineWindow localWindow):
			entityManager(new EntityManager()),
			window(localWindow)
		{}
		//loop that runs while isRunning, runs 
		void sceneLoop();
		//renders all renderable Entites
		void render();
		//initalizes the scene, virtual so will b
		virtual void init();
		
		//gets called by sceneLoop on each frame
		virtual void run();
		
	};
}

