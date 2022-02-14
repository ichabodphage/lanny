#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include "Entity/Managers/EntityManager.hpp"
#include "Scene/BaseScene.hpp"
#include "Event.hpp"
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

		//engine media manager used for handling textures
		GLOBAL_MEDIA mediaManager;

		//component manager used to managing memory pooling of components
		ComponentManagerPtr componentManager;

		//template that makes a shared pointer of a class that extends scene
		template<typename SceneType>
		std::shared_ptr<SceneType> generateScene() {
				return std::make_shared<SceneType>(window, this, &mediaManager, componentManager.get());
		};
		//long long holding current frame
		size_t frame = 0;
		
		const size_t entityLimit;
		//while loop that runs the current scene;
		void runScene();

	public:
		//constructor using video mode, window name, and path to texture file
		LannyEngine(sf::VideoMode video, std::string name,std::string assetPath,size_t maxEntities = 3000):
			componentManager(std::make_unique<ComponentMgr>(maxEntities)),
			window(new sf::RenderWindow(video, name)),
			mediaManager(assetPath), entityLimit(maxEntities) {};

		//inserts a scene into scene map
		template<typename SceneType>
		void loadScene(std::string sceneName) {
			scenes[sceneName] = generateScene<SceneType>();
			std::cout << "loaded scene: " << sceneName << "\n";
			
			
		};

		//begins playing a scene
		void playScene(std::string sceneName);

		//increases frame by one
		void incrementFrame();
		
		//gets the current frame
		size_t getCurrentFrame();

		//gets the max amount of entities
		const size_t getEntityLimit();
		//pools keyboard input
		void input();

		//sends an lny::Event to the scene currentScene containing a keycode and wheather or not a key is pressed
		void sendKeyPress(sf::Event* myKeyEvent, bool isPressed);

		//sends an lny event holding information on the mouse cursor
		void sendMouseEvent(sf::Event* myKeyEvent, bool isPresse,lny::Vec2 mag);

	};

}