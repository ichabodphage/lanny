#include <SFML/Graphics.hpp>
#include <iostream>
#include "engine/LannyEngine.hpp"
#include "rectScene.hpp"


int main()
{   
    lny::LannyEngine myApp(sf::VideoMode(400, 400), "myApp");
    myApp.insertScene("scene1", myApp.generateScene<RectScene>());
    myApp.insertScene("scene2", myApp.generateScene<RectScene>());
    myApp.loadScene("scene1");
    return 0;
}