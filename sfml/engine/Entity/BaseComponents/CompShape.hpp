#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Component.hpp"
namespace lny {
	/*
	* shape entity component used for drawing the entity onto the screen
	*/
	typedef sf::Vector2f Vec2;
	struct CompShape : Compoment {
	public:
		sf::VertexArray verticies;
		Vec2 center = { 0,0 };
		CompShape(sf::PrimitiveType shapeType, int pointCount, Vec2 size) :verticies(shapeType, pointCount) {
			switch (shapeType) {
			case sf::Quads:
				verticies[0].position = { 0,0 };
				verticies[1].position = { size.x,0 };
				verticies[2].position = { size.x,size.y };
				verticies[3].position = { 0,size.y };
			}
			for (int i = 0; i < verticies.getVertexCount(); i++) {
				center.x += verticies[i].position.x;
				center.y += verticies[i].position.y;

			}
			center.x /= verticies.getVertexCount();
			center.y /= verticies.getVertexCount();
		};


	};
}