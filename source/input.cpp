#include "../en-tete/Input.hpp"
#include "../en-tete/Direction.hpp"
#include "../en-tete/Menu.hpp"
#include "../en-tete/Button.hpp"

Direction direction;
bool moved = false;
/**
 * @brief Constructeur de la classe Input.
 * 
 * Initialise l'état des touches à false.
 */
Input::Input() {

    key.left = false;
    key.right = false;
    key.up = false;
    key.down = false;
    key.attack = false;
    key.escape = false;
}

/**
 * @brief Récupère l'état actuel des touches.
 * 
 * @return L'état actuel des touches sous forme d'une structure KeyState.
 */
Input::KeyState Input::getKeyState() {

    return key;
}

/**
 * @brief Gère les événements clavier et souris.
 * 
 * @param event L'événement SFML reçu.
 * @param window La fenêtre de rendu.
 */
void Input::eventListener(Event event, RenderWindow& window) {
    
    if (event.type == Event::Closed) {
        window.close();
    }else if (event.type == Event::MouseButtonPressed || event.type == Event::MouseButtonReleased || event.type == Event::MouseMoved){
        moved = false;
    }else if (event.type == Event::KeyPressed) {

        if (event.key.code == Keyboard::Escape) {
            key.escape = true;
            moved = false;
        }
        if (event.key.code == Keyboard::Z) {
            key.up = true;
            this->game.currentDirection(Direction::UP);
            moved = true;
        }
        if (event.key.code == Keyboard::S) {
            key.down = true;
            this->game.currentDirection(Direction::DOWN);
            moved = true;
        }
        if (event.key.code == Keyboard::Q) {
            key.left = true;
            this->game.currentDirection(Direction::LEFT);
            moved = true;
        }
        if (event.key.code == Keyboard::D) {
            key.right = true;
            this->game.currentDirection(Direction::RIGHT);
            moved = true;
        }
    }else if (event.type == Event::KeyReleased) {
        if (event.key.code == Keyboard::Escape) {
            key.escape = false;
            moved = false;
        }
        if (event.key.code == Keyboard::Z) {
            key.up = false;
            moved = false;
        }
        if (event.key.code == Keyboard::S) {
            key.down = false;
            moved = false;
        }
        if (event.key.code == Keyboard::Q) {
            key.left = false;
            moved = false;
        }
        if (event.key.code == Keyboard::D) {
            key.right = false;
            moved = false;
        }
    }

}

/**
 * @brief Gère les événements de clic de souris sur les boutons "Start" et "Exit".
 * 
 * @param event L'événement SFML reçu.
 * @param buttonStart Le bouton "Start".
 * @param buttonExit Le bouton "Exit".
 * @param window La fenêtre de rendu.
 */
void Input::eventButton(Event event, Button* buttonStart, Button* buttonExit, RenderWindow& window) {
    
    if (event.type == Event::MouseButtonPressed) {

        int mouseX = event.mouseButton.x; 
        int mouseY = event.mouseButton.y; 

        FloatRect buttonStartBounds = buttonStart->getGlobalBounds();
        FloatRect buttonExitBounds = buttonExit->getGlobalBounds();

        if (buttonStartBounds.contains(mouseX, mouseY)) {
            cout << "Button Start Clicked" << endl;
            this->menu->changeGameState(GameState::GAME);
        }

        if (buttonExitBounds.contains(mouseX, mouseY)) {
            cout << "Button Exit Clicked" << endl;
            window.close();
        }
    }
}

bool Input::isMoving(){
    return moved;
}
