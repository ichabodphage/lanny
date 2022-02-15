#include "RenderRect.hpp"
using namespace lny;

RenderRect::RenderRect(lny::Vec2 nsize) :size(nsize), localShape(sf::Quads, 4) {
	localShape[0].position = sf::Vector2f(0, 0);			//top left
	localShape[1].position = sf::Vector2f(size.x, 0);		//top right
	localShape[2].position = sf::Vector2f(size.x, size.y);	//bottom right
	localShape[3].position = sf::Vector2f(0, size.y);		//bottom left
}

RenderRect::RenderRect(lny::Vec2 nsize,sf::Texture * newTexture) :size(nsize), localShape(sf::Quads, 4),rectTexture(newTexture) {
	localShape[0].position = sf::Vector2f(0, 0);			//top left
	localShape[1].position = sf::Vector2f(size.x, 0);		//top right
	localShape[2].position = sf::Vector2f(size.x, size.y);	//bottom right
	localShape[3].position = sf::Vector2f(0, size.y);		//bottom left
	localShape[0].texCoords = sf::Vector2f(0, 0);					//top left
	localShape[1].texCoords = sf::Vector2f(newTexture->getSize().x, 0);			//top right
	localShape[2].texCoords = sf::Vector2f(newTexture->getSize().x, newTexture->getSize().y);	//bottom right
	localShape[3].texCoords = sf::Vector2f(0, newTexture->getSize().y);			//bottom left
}



void RenderRect::setPos(lny::Vec2 pos) {
	localShape[0].position = sf::Vector2f(pos.x, pos.y);					//top left
	localShape[1].position = sf::Vector2f(pos.x + size.x, pos.y);			//top right
	localShape[2].position = sf::Vector2f(pos.x + size.x, pos.y + size.y);	//bottom right
	localShape[3].position = sf::Vector2f(pos.x, pos.y + size.y);			//bottom left
}

sf::VertexArray& RenderRect::getPoints() {
	return localShape;
}

void RenderRect::setFillColor(sf::Color newColor) {
	//go through each vertex of the shape and set its color to newColor
	for (int i = 0; i < 4; i++) {
		localShape[i].color = newColor;
	}
}

void RenderRect::setTexture(sf::Texture* newTexture){
	localShape[0].texCoords = sf::Vector2f(0, 0);					//top left
	localShape[1].texCoords = sf::Vector2f(newTexture->getSize().x, 0);			//top right
	localShape[2].texCoords = sf::Vector2f(newTexture->getSize().x, newTexture->getSize().y);	//bottom right
	localShape[3].texCoords = sf::Vector2f(0, newTexture->getSize().y);			//bottom left
	rectTexture = newTexture;
}

sf::Texture* RenderRect::getTexture(){
	return rectTexture;
}