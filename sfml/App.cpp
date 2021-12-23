#include "App.hpp"
#include "engine/Components.hpp"
#include <random>
void App::init() {
	isRunning = true;
	run();
}

void App::run() {
	while (isRunning) {
		handleEvents();
		render();
		addRedSquare();
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
			addRedSquare();
		}
	}
}

void App::addRedSquare() {
	//RNG stuff
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_real_distribution<float> distrP(-50, 400); // define the range
	std::uniform_real_distribution<float> distrS(0, 100); // define the range
	std::uniform_int_distribution<> distrC(0, 255); // define the range
	//make shared ptr of new redSquare
	auto square = entityManager->insertEntity(REGULAR);

	//initalize red square entity component values;
	square->cPosition = std::shared_ptr<CompPosition>(new CompPosition({ distrP(gen),distrP(gen) }));
	square->cShape = std::shared_ptr<CompShape>(new CompShape({ distrS(gen),distrS(gen) }, sf::Color(distrC(gen), distrC(gen), distrC(gen))));
	square->cShape->rect.setPosition(square->cPosition->positionXy);
}

void App::render() {
	window->clear();
	for (auto& entity : entityManager->entities) {
		window->draw(entity->cShape->rect);
	}
	window->display();
}