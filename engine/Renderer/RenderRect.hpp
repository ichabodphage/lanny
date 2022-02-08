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
			sf::VertexArray points(sf::Quads,4);
			//length and width of rectangle
			lny::Vec2 size;
		public:
			//constructor using size of rect
			RenderRect(lny::Vec2 nsize):size(nsize){
				points[0].position = sf::Vector2f(0,0);
				points[1].position = sf::Vector2f(size.x,0);
				points[2].position =sf::Vector2f(size.x,size.y);
				points[3].position = sf::Vector2f(0,size.y);
			}
			void setPos(lny::Vec2 pos){
				points[0].position = sf::Vector2f(pos.x,pos.y);
				points[1].position = sf::Vector2f(pos.x+size.x,pos.y);
				points[2].position =sf::Vector2f(pos.x+size.x,pos.y+size.y);
				points[3].position = sf::Vector2f(pos.x,pos.y+size.y);
			}
			sf::VertexArray getPoints(){
				return points;
			}
	}

}