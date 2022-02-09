#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
namespace lny{
	/*
	* RenderRect class use to help with rendering sprites
	* only stores vertecies and dimensions of the rectangle, does not store 
  * any transforms
	*/
	class RenderRect{
		private:
			//vertex array of all the rectangles points
			sf::VertexArray localShape;
			//length and width of rectangle
			lny::Vec2 size;
		public:
			//constructor using size of rect
			RenderRect(lny::Vec2 nsize):size(nsize),localShape(sf::Quads,4){
				localShape[0].position = sf::Vector2f(0,0);
				localShape[1].position = sf::Vector2f(size.x,0);
				localShape[2].position =sf::Vector2f(size.x,size.y);
				localShape[3].position = sf::Vector2f(0,size.y);
			}
			//changes the position of the vertex array
			void setPos(lny::Vec2 pos){
				localShape[0].position = sf::Vector2f(pos.x,pos.y);
				localShape[1].position = sf::Vector2f(pos.x+size.x,pos.y);
				localShape[2].position =sf::Vector2f(pos.x+size.x,pos.y+size.y);
				localShape[3].position = sf::Vector2f(pos.x,pos.y+size.y);
			}
			//returns all the points in the vertex array
			sf::VertexArray getPoints(){
				return localShape;
			}
			void setFillColor(sf::Color newColor){
				for(int i = 0; i < 4;i++){
					localShape[i].color = newColor;
				}
			}
	};

}