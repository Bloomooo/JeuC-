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
    void currentDirection(Direction direction);
    void setTexturePos(int posX, int posY);
    string directionToString(Direction direction);

private:
    Texture perso;
    Sprite persoSprite;
    Vector2i animation;
};

#endif // !GAME_HPP
