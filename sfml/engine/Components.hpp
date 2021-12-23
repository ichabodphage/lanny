#pragma once
#include <SFML/Graphics.hpp>
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
	CompShape(){};

	void makeSquare(XyVector size) {
		shape.setPointCount(4);
		shape.setPoint(0, { 0,0 });			 //top left of square
		shape.setPoint(1, { size.x,0 });	 //top right
		shape.setPoint(2, { size.x,size.y });//bottom right
		shape.setPoint(3, { 0,size.y });	 //bottom left
	}
	void tint(sf::Color c) {
		shape.setFillColor(c);
	}
};

