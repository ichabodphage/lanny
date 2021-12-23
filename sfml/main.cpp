#include <SFML/Graphics.hpp>
#include <iostream>
#include "engine/EntityManager.hpp"
#include "engine/Entity.hpp"
#include "App.hpp"



int main()
{   
    App myApp(sf::VideoMode(400, 400), "myApp");
    myApp.init();
    return 0;
}