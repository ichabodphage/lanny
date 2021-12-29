#include <SFML/Graphics.hpp>
#include <iostream>
#include "engine/LannyEngine.hpp"
#include "rectScene.hpp"


int main()
{   
    lny::LannyEngine myApp(sf::VideoMode(1280, 720), "myApp","TextureAssets");
    myApp.insertScene("scene1", myApp.generateScene<RectScene>());
    myApp.loadScene("scene1");
    return 0;
}