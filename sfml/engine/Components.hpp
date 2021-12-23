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
	sf::RectangleShape rect; //rectangle shape for rendering
	CompShape(XyVector size, sf::Color shapeColor) :rect(size) { //constructor using size and color of rectangle
		rect.setFillColor(shapeColor);
	};
};
