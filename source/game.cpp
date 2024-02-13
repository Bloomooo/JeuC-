#include "../en-tete/Game.hpp"
#include "../en-tete/Input.hpp"

Input inputAnim;
int y=static_cast<int>(Direction::RIGHT);
bool updateFPS = true;
Clock gameTime;
float fpsCount = 0,
      switchFPS = 100,
      fpsSpeed = 500;
View view;

Game::Game(){
    this->animation.x = 0;
    this->animation.y = static_cast<int>(Direction::RIGHT);
}

void Game::loadTextures(){
    if(!this->perso.loadFromFile("ressource/perso.png")){
        cout << "texture loaded failed !" << endl;
    }
    this->perso.setSmooth(true);
    this->persoSprite.setTexture(this->perso);
    
    if(updateFPS){
        fpsCount += fpsSpeed * gameTime.restart().asSeconds();
    }else{
        fpsCount = 0;
    }

    if(fpsCount >= switchFPS){
        if(inputAnim->isMoving()){
            this->animation.x++;
            if (this->animation.x >= 3) {
                this->animation.x = 0;
            }
        }
    }
    
    this->animation.y = y;

    int frameWidth = static_cast<int>(this->perso.getSize().x) / 3; // Largeur d'une frame
    int frameHeight = static_cast<int>(this->perso.getSize().y) / 4; // Hauteur d'une frame
    
    this->persoSprite.setTextureRect(IntRect(this->animation.x * frameWidth, this->animation.y * frameHeight, frameWidth, frameHeight));
    
}

void Game::viewLoad(RenderWindow& window) {
    view.reset(FloatRect(0, 0, window.getSize().x, window.getSize().y));
    Vector2f position(window.getSize().x/2, window.getSize().y/2);
    position.x = persoSprite.getPosition().x + 16-(window.getSize().x-150); 
    position.y = persoSprite.getPosition().y + 16-(window.getSize().y-150); 
    if (position.x < 0){
        position.x = 0;
    }
    if(position.y < 0){
        position.y = 0;
    }
    view.reset(FloatRect(position.x, position.y, 1920, 1080));
}
void Game::drawGame(RenderWindow& window){
    loadTextures();
    viewLoad(window);
    window.clear();
    window.setView(view);
    window.draw(this->persoSprite);
}

void Game::currentDirection(Direction direction){
    this->animation.x = 0;
    this->animation.y = static_cast<int>(direction); 

    int frameWidth = static_cast<int>(this->perso.getSize().x) / 3;
    int frameHeight = static_cast<int>(this->perso.getSize().y) / 4;
    this->persoSprite.setTextureRect(IntRect(this->animation.x * frameWidth, this->animation.y * frameHeight, frameWidth, frameHeight));
}


void Game::setTexturePos(int posX, int posY){
    this->persoSprite.setPosition(Vector2f(posX, posY));

}

string Game::directionToString(Direction direction) {
    switch (direction) {
        case Direction::UP:
            return "UP";
        case Direction::DOWN:
            return "DOWN";
        case Direction::LEFT:
            return "LEFT";
        case Direction::RIGHT:
            return "RIGHT";
        default:
            return "UNKNOWN";
    }
}