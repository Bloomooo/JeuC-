#include "../en-tete/Game.hpp"

Vector2i anim(1, static_cast<int>(Direction::UP));
Game::Game(){
}

void Game::loadTextures(){
    if(!this->perso.loadFromFile("ressource/perso.jpg",IntRect(0,0,110,160))){
        cout << "texture loaded failed !" << endl;
    }
    this->perso.setSmooth(true);
    anim.x++;
    if (anim.x >= static_cast<int>(perso.getSize().x)) {
    anim.x = 0;
}
    this->persoSprite.setTextureRect(IntRect(anim.x*32, anim.y*32, 32, 32));
}

void Game::drawGame(RenderWindow& window){
    window.clear();
    loadTextures();
    window.draw(this->persoSprite);
}
