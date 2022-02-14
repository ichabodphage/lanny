#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "RenderRect.hpp"
#include "../Entity/Managers/EntityManager.hpp"
namespace lny {
	/*
	* RenderBatch class exists to batch RenderRect objects into one
	* vertex array to reduce draw calls
	*/
	class RenderBatch {
	private:
		//vertex array holding all verticies
		std::vector<sf::Vertex> vertexArr;
		//texure used inside of the batch
		std::shared_ptr<sf::Texture> drawTexture;
		//curent amount of items in the batch
		size_t currentBatchSize = 0;

		//constant holding the max size of a render batch
		const size_t maxSize;
	public:
		//default constructor
		RenderBatch(size_t maxBatchSize);

		//adds the verticies of a RenderRect to the batch
		void addVerticies(lny::RenderRect *rectToInsert);

		//resets the batch to contain 0 items
		void clear();

		//gets the current size of the batch
		size_t size();

		//retuns the vertex array
		std::vector<sf::Vertex>& getVerticies();
	};
}