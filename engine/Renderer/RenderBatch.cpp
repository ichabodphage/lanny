#include "RenderBatch.hpp"
using namespace lny;


RenderBatch::RenderBatch(size_t maxBatchSize):maxSize(maxBatchSize)
{
	vertexArr.reserve(maxBatchSize*4);
}

void RenderBatch::addVerticies(lny::RenderRect* rectToInsert)
{
	if (currentBatchSize != maxSize) {
		//get all the verticies inside of the renderRect and add them to the vertex array
		sf::VertexArray verticies = rectToInsert->getPoints();
		for (int i = 0; i < 4; i++) {
			vertexArr[i + (currentBatchSize * 4)] = verticies[i];
		}
		currentBatchSize++;
	}
}

void lny::RenderBatch::clear()
{
	currentBatchSize = 0;
}

size_t lny::RenderBatch::size()
{
	return currentBatchSize;
}

std::vector<sf::Vertex>& lny::RenderBatch::getVerticies()
{
	return vertexArr;
}
