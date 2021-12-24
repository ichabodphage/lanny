#include <SFML/Graphics.hpp>
#include <iostream>
#include "engine/EntityManager.hpp"
#include "engine/Entity.hpp"
#include "LannyEngine.hpp"
#include "rectScene.hpp"


int main()
{   
    lny::LannyEngine myApp(sf::VideoMode(400, 400), "myApp");
    myApp.insertScene("scene1", myApp.generateScene<RectScene>());
    myApp.loadScene("scene1");
    return 0;
}