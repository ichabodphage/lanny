#include "RenderBatch.hpp"
using namespace lny;


RenderBatch::RenderBatch(size_t maxBatchSize):maxSize(maxBatchSize)
{
	vertexArr.reserve(maxBatchSize*4);
}

//constructor using texture
RenderBatch::RenderBatch(size_t maxBatchSize, sf::Texture* texture):maxSize(maxBatchSize),batchTexture(texture){
	vertexArr.reserve(maxBatchSize*4);
};
void RenderBatch::addVerticies(lny::RenderRect rectToInsert)
{
	if (currentBatchSize < maxSize) {
		//get all the verticies inside of the renderRect and add them to the vertex array
		sf::Vertex* verticies = rectToInsert.getPoints();
		for (int i = 0; i < 4; i++) {
			vertexArr[i + (currentBatchSize * 4)] = verticies[i];
		}
		currentBatchSize++;
	}
}

void RenderBatch::clear()
{
	currentBatchSize = 0;
}

size_t RenderBatch::size()
{
	return currentBatchSize;
}

std::vector<sf::Vertex>& RenderBatch::getVerticies()
{
	return vertexArr;
}

void RenderBatch::draw(sf::RenderTarget& target, sf::RenderStates states)const{
	states.texture = batchTexture;
	states.transform = getTransform();
target.draw(vertexArr.data(),currentBatchSize*4,sf::Quads,states);
}