#pragma once
#include <SFML/Graphics.hpp>
#include "engine/EntityManager.hpp"
#include "engine/BaseScene.hpp"
enum EntType {
	REGULAR = 0
};
typedef std::shared_ptr<sf::RenderWindow> EngineWindow;
typedef std::shared_ptr<lny::BaseScene> ScenePtr;
typedef std::map<std::string, ScenePtr> SceneMap;
//App class handles the window and the entity manager
namespace lny {
	class LannyEngine
	{
	private:
		EngineWindow window;
		SceneMap scenes;
	public:
		LannyEngine(sf::VideoMode video, std::string name) :
			window(new sf::RenderWindow(video, name)) {};

		//inserts a scene into scenes
		void insertScene(std::string sceneName, ScenePtr scene);

		void loadScene(std::string sceneName);

		template<typename SceneType>
		std::shared_ptr<SceneType> generateScene() {
			return std::make_shared<SceneType>(window);
		}
	};

}