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
	class RenderBatch : public sf::Drawable, sf::Transformable{
	private:
		//vertex array holding all verticies
		std::vector<sf::Vertex> vertexArr;

		//texture used by the render batch
		sf::Texture*  batchTexture;

		//curent amount of items in the batch
		size_t currentBatchSize = 0;
		//constant holding the max size of a render batch
		const size_t maxSize;
	public:
		//default constructor
		RenderBatch(size_t maxBatchSize);

		//constructor using texture
		RenderBatch(size_t maxBatchSize, sf::Texture* texture);

		//adds the verticies of a RenderRect to the batch
		void addVerticies(lny::RenderRect rectToInsert);

		//resets the batch to contain 0 items
		void clear();

		//gets the current size of the batch
		size_t size();

		//retuns the vertex array
		std::vector<sf::Vertex>& getVerticies();

		//draws the contents of the render batch
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	};
}