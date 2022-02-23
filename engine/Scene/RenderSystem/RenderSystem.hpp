#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include "../../Renderer/Texture.hpp"
#include "../../Renderer/RenderRect.hpp"
#include "../../Renderer/RenderBatch.hpp"
#include "../../Entity/Entity.hpp"
#include "../../Entity/Managers/EntityManager.hpp"

namespace lny{
	/*
	*	standard renderer class used to batch render entities
	*/
	class RenderSystem {
	private:
		//map using texture keys and render batch pairs
		std::map<sf::Texture*,lny::RenderBatch> batchMap;

		//pointer back to the window
		std::shared_ptr<sf::RenderWindow> localWindow;

		//pointer back to scenes entity manager
		lny::EntityManager* entityManager;
		//max batch size
		const size_t maxSize;

		//inserts a renderable entity into the renderer
		void insertEntity(lny::Entity& entity);

	public:
		//default constructor
		RenderSystem(std::shared_ptr<sf::RenderWindow> win,lny::EntityManager* manager,size_t max);

		//renders all entities in the batchMap
		void render();

		//method that makes the RenderBatches for the BatchMap
		void makeBatches();

		size_t batchSize(){
			return batchMap.size();
		}
		//clears out all the batches
		void clearBatches();
	};
}