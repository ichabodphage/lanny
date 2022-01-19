#include <SFML/Graphics.hpp>
#include <iostream>
#include "engine/LannyEngine.hpp"
#include "demos/ColisonScene.hpp"
#include "demos/TextureScene.hpp"
#include "demos/LargeEntityCountScene.hpp"
#include "engine/Entity/ComponentManager.hpp"
int main()
{   
    lny::LannyEngine myApp(sf::VideoMode(1280, 720), "myApp","TextureAssets",100000);
    myApp.insertScene("scene1",myApp.generateScene<ColisonScene>());
    myApp.insertScene("scene2", myApp.generateScene<TextureScene>());
    myApp.insertScene("scene3", myApp.generateScene<LargeEntityCountScene>());
    myApp.loadScene("scene1");
    return 0;
}