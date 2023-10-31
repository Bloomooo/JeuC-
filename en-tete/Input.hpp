#ifndef INPUT_HPP
#define INPUT_HPP

#include <SFML/Graphics.hpp>
#include "../en-tete/Menu.hpp"

#include <iostream>

using namespace std;
using namespace sf;

class Input {
    struct KeyState {
        bool left;     ///< État de la touche gauche.
        bool right;    ///< État de la touche droite.
        bool up;       ///< État de la touche vers le haut.
        bool down;     ///< État de la touche vers le bas.
        bool attack;   ///< État de la touche d'attaque.
        bool escape;   ///< État de la touche d'échappement.
    };
    
public:
    /// Constructeur par défaut de la classe Input.
    Input();

    /// Écouteur d'événements pour la gestion des entrées utilisateur.
    void eventListener(Event event, RenderWindow& window);

    /// Gère les événements de clic de souris pour les boutons.
    /// @param event Événement de la souris.
    /// @param button Pointeur vers le bouton "Start".
    /// @param buttonExit Pointeur vers le bouton "Exit".
    /// @param window Fenêtre de rendu.
    void eventButton(Event event, Button *button, Button* buttonExit, RenderWindow& window);

    /// Récupère l'état actuel des touches.
    /// @return Structure KeyState représentant l'état des touches.
    KeyState getKeyState();
    
private:
    KeyState key; ///< État des touches.
    Game game; ///< Instance de la classe Game.
    Menu menu; ///< Instance de la classe Menu.
};

#endif // INPUT_HPP
