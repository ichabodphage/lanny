#pragma once
#include <SFML/Graphics.hpp>
#include "Entity/EntityManager.hpp"
#include "BaseScene.hpp"
#include "Event.hpp"
#include "Media/MediaManager.hpp"
enum EntType {
	REGULAR = 0
};
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
		lny::MediaManager mediaManager;

		unsigned long long frame = 0;
	public:
		
		//constructor using video mode, window name, and path to texture file
		LannyEngine(sf::VideoMode video, std::string name,std::string mediaPath):
			window(new sf::RenderWindow(video, name)),
			mediaManager(mediaPath){};

		//inserts a scene into scene map
		void insertScene(std::string sceneName, ScenePtr scene);

		//gets a scene with sceneName
		ScenePtr getScene(std::string sceneName);
		
		//returns currentScene
		ScenePtr getCurrentScene();

		//loads a scene if it is in the scene map
		void loadScene(std::string sceneName);

		//increases frame by one
		void incrementFrame();
		
		//gets the current frame
		unsigned long long getCurrentFrame();

		//pools keyboard input
		void input();

		//sends an lny::Event to the scene currentScene containing a keycode and wheather or not a key is pressed
		void sendKeyPress(sf::Event* myKeyEvent, bool isPressed);

		//template that makes a shared pointer of a class that extends scene
		template<typename SceneType>
		std::shared_ptr<SceneType> generateScene() {
			return std::make_shared<SceneType>(window, this, &mediaManager);
		};
	};

}