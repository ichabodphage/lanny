#pragma once
#include <SFML/Graphics.hpp>
namespace lny {
	typedef sf::Vector2f XyVector;
	//position entity Component
	struct CompPosition {
		XyVector positionXy = { 0,0 };		//position vector
		XyVector velocityXy = { 0,0 };		//velocity vector
		XyVector accelerationXy = { 0,0 };	//acceleration vector

		CompPosition(XyVector pos) : positionXy(pos) {}			//constructor to initalize position
		CompPosition(XyVector pos, XyVector vel) :				//constructor to initalize position and velocity
			positionXy(pos),
			velocityXy(vel) {}
		CompPosition(XyVector pos, XyVector vel, XyVector acc) ://constructor to initalize position, velocity, and acceleration 
			positionXy(pos),
			velocityXy(vel),
			accelerationXy(acc) {}
	};

	//shape entity component used for rendering the entity
	struct CompShape {
	public:
		sf::ConvexShape shape; //rectangle shape for rendering
		CompShape() {};
		//makes shape into a rectangle
		void rect(XyVector size) {
			shape.setPointCount(4);
			shape.setPoint(0, { 0,0 });			 //top left corner
			shape.setPoint(1, { size.x,0 });	 //top right corner
			shape.setPoint(2, { size.x,size.y });//bottom right corner
			shape.setPoint(3, { 0,size.y });	 //bottom left corner
		}
		//makes shape into right triangle
		void rightTriangle(XyVector size) {
			shape.setPointCount(3);
			shape.setPoint(0, { 0,0 });			 //top left corner
			shape.setPoint(1, { size.x,size.y });//bottom right corner
			shape.setPoint(2, { 0,size.y });	 //bottom left
		}
		void triangle(XyVector size) {
			shape.setPointCount(3);
			shape.setPoint(0, { size.x / 2,0 }); //middle of shape in x
			shape.setPoint(1, { size.x,size.y });//bottom right corner
			shape.setPoint(2, { 0,size.y });	 //bottom left
		}
		void tint(sf::Color c) {
			shape.setFillColor(c);
		}
	};

	//texture entity component used to texture entities
	struct CompTexture {
		std::shared_ptr<sf::Texture> texture;
		CompTexture(std::shared_ptr<sf::Texture> tex) :texture(tex) {};
	};
};