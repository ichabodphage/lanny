#include "App.hpp"
#include "engine/Components.hpp"
#include <random>
#include <iostream>
void App::init() {
	isRunning = true;
	run();
}

void App::run() {
	while (isRunning) {
		handleEvents();
		render();
	}
}

void App::handleEvents() {
	sf::Event event;
	while (window->pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed) {
			isRunning = false;
			window->close();
		}
		if (event.type == sf::Event::MouseButtonPressed){
			addSquare();
		}
	}
}

void App::addSquare() {

	//RNG stuff
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_real_distribution<float> distrP(-50, 400); // define the range
	std::uniform_real_distribution<float> distrS(0, 100); // define the range
	std::uniform_int_distribution<> distrC(0, 255); // define the range
	//make shared ptr of new redSquare
	auto square = entityManager->insertEntity(REGULAR);

	//initalize red square entity component values;
	square->cPosition = std::shared_ptr<lny::CompPosition>(new lny::CompPosition({ distrP(gen),distrP(gen) }));
	square->cShape = std::shared_ptr<lny::CompShape>(new lny::CompShape());
	square->cShape->shape.setPosition(square->cPosition->positionXy);
	square->cShape->triangle({ distrS(gen),distrS(gen) }); //make square shape
	square->cShape->tint(sf::Color(distrC(gen), distrC(gen), distrC(gen), distrC(gen))); //generate random RGBA color
	
}

void App::render() {
	window->clear();
	for (auto& entity : entityManager->entities) {
		window->draw(entity->cShape->shape);
	}
	window->display();
}