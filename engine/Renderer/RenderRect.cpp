#include "RenderRect.hpp"
using namespace lny;

RenderRect::RenderRect(lny::Vec2 nsize) :size(nsize){
	localShape[0].position = sf::Vector2f(0, 0);			//top left
	localShape[1].position = sf::Vector2f(size.x, 0);		//top right
	localShape[2].position = sf::Vector2f(size.x, size.y);	//bottom right
	localShape[3].position = sf::Vector2f(0, size.y);		//bottom left
}

RenderRect::RenderRect(lny::Vec2 nsize,lny::Texture * newTexture) :size(nsize),rectTexture(newTexture->textureImage.get()) {
	//top left
	localShape[0].position = sf::Vector2f(0, 0);
	//top right
	localShape[1].position = sf::Vector2f(size.x, 0);
	//bottom right
	localShape[2].position = sf::Vector2f(size.x, size.y);
	//bottom left
	localShape[3].position = sf::Vector2f(0, size.y);		

	//top left
	localShape[0].texCoords = sf::Vector2f(
	newTexture->offset.x, newTexture->offset.y);											
	//top right
	localShape[1].texCoords = sf::Vector2f(
	newTexture->offset.x + newTexture->size.x, 
	newTexture->offset.y);
	
	//bottom right
	localShape[2].texCoords = sf::Vector2f(
	newTexture->offset.x +newTexture->size.x, 
	newTexture->offset.y + newTexture->size.y);
	
	//bottom left
	localShape[3].texCoords = sf::Vector2f(
	newTexture->offset.x,
	newTexture->offset.y + newTexture->size.y);			
}



void RenderRect::setPos(lny::Vec2 pos) {
	//top left
	localShape[0].position = 
	sf::Vector2f(pos.x, pos.y);
	//top right
	localShape[1].position = 
	sf::Vector2f(pos.x + size.x, pos.y);
	//bottom right
	localShape[2].position = 
	sf::Vector2f(pos.x + size.x, pos.y + size.y);	
	//bottom left
	localShape[3].position = 
	sf::Vector2f(pos.x, pos.y + size.y);
}

sf::Vertex* RenderRect::getPoints() {
	return localShape;
}

void RenderRect::setFillColor(sf::Color newColor) {
	//set each color in local shape to newColor
	for (int i = 0; i < 4; i++) {
		localShape[i].color = newColor;
	}
}

void RenderRect::setTexture(lny::Texture* newTexture){
	//top left
	localShape[0].texCoords = 
	sf::Vector2f(
	newTexture->offset.x, 
	newTexture->offset.y);
	
	//top right
	localShape[1].texCoords = 
	sf::Vector2f(
	newTexture->offset.x + newTexture->size.x,
	newTexture->offset.y); 
	
	//bottom right
	localShape[2].texCoords = 
	sf::Vector2f(
	newTexture->offset.x + newTexture->size.x,
	newTexture->offset.y + newTexture->size.y);
	
	//bottom left
	localShape[3].texCoords = 
	sf::Vector2f(
	newTexture->offset.x,
	newTexture->offset.y + newTexture->size.y);
	
	rectTexture = newTexture->textureImage.get();
}

sf::Texture* RenderRect::getTexture(){
	return rectTexture;
}