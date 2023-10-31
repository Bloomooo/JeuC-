#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "../en-tete/Direction.hpp"
#include <iostream>

using namespace std;
using namespace sf;

class Game{

public:
    Game();
    void loadTextures();
    void drawGame(RenderWindow& window);
    
private:
    Texture perso;
    Sprite persoSprite;
    
    Direction direction;
    
};

#endif // !GAME_HPP
