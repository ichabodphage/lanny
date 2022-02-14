#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
namespace lny {
	typedef sf::Vector2f Vec2;
	/*
	* RenderRect class use to help with rendering sprites
	* only stores vertecies and dimensions of the rectangle, does not store
  * any transforms
	*/
	class RenderRect {

	private:
		//vertex array of all the rectangles points
		sf::VertexArray localShape;
		//length and width of rectangle
		lny::Vec2 size;
	public:
		//constructor using size of rect
		RenderRect(lny::Vec2 nsize);
		//changes the position of the vertex array
		void setPos(lny::Vec2 pos);
		//returns all the points in the vertex array
		sf::VertexArray& getPoints();
		//sets all points of the shape to a specific color
		void setFillColor(sf::Color newColor);

	};

}