#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Texture.hpp"
namespace lny {
	typedef sf::Vector2f Vec2;
	/*
	* RenderRect class use to help with rendering sprites
	* only stores vertecies and dimensions of the rectangle.
	*/
	class RenderRect {
	private:
		//vertex array of all the rectangles points,
		sf::Vertex localShape[4];

		//length and width of rectangle
		lny::Vec2 size;
		//texture of the rectangle
		sf::Texture* rectTexture = nullptr;
	public:
		//constructor using size of rect
		RenderRect(lny::Vec2 nsize);

		//constructor using size of rect and texture
		RenderRect(lny::Vec2 nsize, lny::Texture* newTexture);
		//changes the position of the vertex array
		void setPos(lny::Vec2 pos);

		//returns all the points in the vertex array
		sf::Vertex* getPoints();

		//sets all points of the shape to a specific color
		void setFillColor(sf::Color newColor);

		//sets the texture of the RenderRect
		void setTexture(lny::Texture * newTexture);

		//returns the RenderRect's texture
		sf::Texture * getTexture();
	};

}