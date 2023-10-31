#include "../en-tete/Input.hpp"
#include "../en-tete/Direction.hpp"

Direction direction;
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
        // Si l'événement est la fermeture de la fenêtre, on ferme la fenêtre de l'application
        window.close();
    }

    if (event.type == Event::KeyPressed) {
        // Si une touche est pressée, on vérifie laquelle
        if (event.key.code == Keyboard::Escape) {
            key.escape = true;
        }
        if (event.key.code == Keyboard::Z) {
            direction = Direction::UP;
            key.up = true;
        }
        if (event.key.code == Keyboard::S) {
            direction = Direction::DOWN;
            key.down = true;
        }
        if (event.key.code == Keyboard::Q) {
            direction = Direction::RIGHT;
            key.left = true;
        }
        if (event.key.code == Keyboard::D) {
            direction = Direction::LEFT;
            key.right = true;
        }
    }

    if (event.type == Event::KeyReleased) {
        // Si une touche est relâchée, on vérifie laquelle
        if (event.key.code == Keyboard::Escape) {
            key.escape = false;
        }
        if (event.key.code == Keyboard::Z) {
            key.up = false;
        }
        if (event.key.code == Keyboard::S) {
            key.down = false;
        }
        if (event.key.code == Keyboard::Q) {
            key.left = false;
        }
        if (event.key.code == Keyboard::D) {
            key.right = false;
        }
    }

    if (event.type == Event::MouseButtonPressed) {
        // Si un bouton de la souris est pressé, on vérifie lequel
        if (event.mouseButton.button == Mouse::Left) {
            key.attack = true;
        }
    }

    if (event.type == Event::MouseButtonReleased) {
        // Si un bouton de la souris est relâché, on vérifie lequel
        if (event.mouseButton.button == Mouse::Left) {
            key.attack = false;
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
        // Si un bouton de la souris est pressé, on vérifie s'il est sur un bouton
        int mouseX = event.mouseButton.x; // Coordonnée en x du clic de souris
        int mouseY = event.mouseButton.y; // Coordonnée en y du clic de souris

        // Obtenir les coordonnées des boutons "Start" et "Exit"
        FloatRect buttonStartBounds = buttonStart->getGlobalBounds();
        FloatRect buttonExitBounds = buttonExit->getGlobalBounds();

        // Vérifier si le clic de souris est à l'intérieur des limites du bouton "Start"
        if (buttonStartBounds.contains(mouseX, mouseY)) {
            cout << "Button Start Clicked" << endl;
            // Exécuter l'action associée au bouton "Start"
            this->menu.changeGameState(GameState::GAME);
        }

        // Vérifier si le clic de souris est à l'intérieur des limites du bouton "Exit"
        if (buttonExitBounds.contains(mouseX, mouseY)) {
            cout << "Button Exit Clicked" << endl;
            // Exécuter l'action associée au bouton "Exit"
            // Par exemple, ici, on ferme la fenêtre de l'application
            window.close();
        }
    }
}
