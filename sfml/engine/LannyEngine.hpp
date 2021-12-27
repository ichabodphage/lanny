#pragma once
#include <SFML/Graphics.hpp>
#include "Entity/EntityManager.hpp"
#include "BaseScene.hpp"
#include "Event.hpp"
enum EntType {
	REGULAR = 0
};
//App class handles the window and the entity manager
namespace lny {
	typedef std::shared_ptr<sf::RenderWindow> EngineWindow;
	typedef std::shared_ptr<lny::BaseScene> ScenePtr;
	typedef std::map<std::string, ScenePtr> SceneMap;
	class LannyEngine
	{
	private:
		EngineWindow window;
		SceneMap scenes;
		std::string currentScene;
	public:
		long frame = 0;
		LannyEngine(sf::VideoMode video, std::string name) :
			window(new sf::RenderWindow(video, name)) {};

		//inserts a scene into scenes
		void insertScene(std::string sceneName, ScenePtr scene);

		void loadScene(std::string sceneName);

		void sendKeyPress(sf::Event * myKeyEvent);
		// gets the current scene
		ScenePtr getCurrentScene(std::string sceneName);
		void input();

		template<typename SceneType>
		std::shared_ptr<SceneType> generateScene() {
			return std::make_shared<SceneType>(window,this);
		}
	};

}