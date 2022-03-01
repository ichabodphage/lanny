#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include <chrono>
#include <thread>

#include "Entity/Managers/EntityManager.hpp"
#include "Scene/BaseScene.hpp"
#include "Input/Event.hpp"
#include "Typedefs.hpp"

//App class handles the window and the entity manager
namespace lny {
	typedef std::shared_ptr<sf::RenderWindow> EngineWindow;
	typedef std::shared_ptr<lny::BaseScene> ScenePtr;
	typedef std::map<std::string, ScenePtr> SceneMap;

	/*
	* LannyEngine is a class that is used to handle loading of scenes along with the handling of media
	* specifically it determines which scenes should be active, and acts as an interface for the scenes to interact with the MediaManager class
	*/
	class LannyEngine
	{
	private:
		//sfml window
		EngineWindow window;

		//ordered map that contains scenes
		SceneMap scenes;

		//currently loaded scene
		ScenePtr currentScene;

		//engine media manager used for handling loading and distribution of media
		GLOBAL_MEDIA mediaManager;

		//component manager used to managing memory pooling of components
		ComponentManagerPtr componentManager;

		//template that makes a shared pointer of a class that extends scene
		template<typename SceneType>
		std::shared_ptr<SceneType> generateScene() {
				return std::make_shared<SceneType>(window, this, &mediaManager, componentManager.get());
		};
	
		//scene loop that runs the current scene;
		void runScene();

		//tells the current scene to poll for user input
		void input();
	public:
		/*millisecond delay time to prevent too much CPU usage
		* public as no undefined behavior is caused by modifying it
		* currently not actually implemented 
		*/
		size_t delay = 1;
		//constructor using video mode, window name, and path to texture file
		LannyEngine(sf::VideoMode video, std::string name,std::string assetPath,size_t maxEntities = 3000):
			componentManager(std::make_unique<ComponentMgr>(maxEntities)),
			window(new sf::RenderWindow(video, name)),
			mediaManager(assetPath){};

		//inserts a scene into scene map
		template<typename SceneType>
		void loadScene(std::string sceneName) {
			scenes[sceneName] = generateScene<SceneType>();
			std::cout << "loaded scene: " << sceneName << "\n";
			
			
		};

		//begins playing a scene
		void playScene(std::string sceneName);




	};

}