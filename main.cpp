#include <SFML/Graphics.hpp>
#include <iostream>
#include "engine/LannyEngine.hpp"
#include "demos/ColisonScene.hpp"
#include "demos/TextureScene.hpp"
#include "demos/LargeEntityCountScene.hpp"
#include "demos/MusicScene.hpp"
int main()
{   
    lny::LannyEngine myApp(sf::VideoMode(440, 440), "myApp","Assets/TextureAssets","Assets/MusicAssets", 10000);
    myApp.loadScene<ColisonScene>("scene1");
    myApp.loadScene<TextureScene>("scene2");
    myApp.loadScene<LargeEntityCountScene>("scene3");
    myApp.loadScene<MusicScene>("scene4");
    myApp.playScene("scene1");
    return 0;
}