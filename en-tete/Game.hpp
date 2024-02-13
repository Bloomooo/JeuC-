#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "../en-tete/Direction.hpp"
#include <iostream>

using namespace std;
using namespace sf;
class Input;
/**
 * @class Game
 * @brief Classe représentant le jeu et ses fonctionnalités.
 */
class Game {
private:
    Input* inputAnim; /**< Gestionnaire d'entrée pour l'animation */
    int y; /**< Direction de l'animation */
    bool updateFPS; /**< Booléen indiquant si la fréquence d'images doit être mise à jour */
    Clock gameTime; /**< Horloge pour le temps de jeu */
    float fpsCount; /**< Compteur de FPS */
    float switchFPS; /**< Fréquence de changement de FPS */
    float fpsSpeed; /**< Vitesse de FPS */
    View view; /**< Vue de la caméra */

    Texture perso; /**< Texture du personnage */
    Sprite persoSprite; /**< Sprite du personnage */
    Vector2i animation; /**< Animation du personnage */

public:
    /**
     * @brief Constructeur par défaut de la classe Game.
     */
    Game();

    /**
     * @brief Charge les textures et gère l'animation du jeu.
     */
    void loadTextures();

    /**
     * @brief Charge la vue de la caméra.
     * @param window Fenêtre de rendu.
     */
    void viewLoad(RenderWindow& window);

    /**
     * @brief Dessine le jeu.
     * @param window Fenêtre de rendu.
     */
    void drawGame(RenderWindow& window);

    /**
     * @brief Définit la direction actuelle du personnage.
     * @param direction Direction du personnage.
     */
    void currentDirection(Direction direction);

    /**
     * @brief Définit la position de la texture du personnage.
     * @param posX Position en X.
     * @param posY Position en Y.
     */
    void setTexturePos(int posX, int posY);

    /**
     * @brief Convertit une direction en chaîne de caractères.
     * @param direction Direction à convertir.
     * @return Chaîne de caractères représentant la direction.
     */
    string directionToString(Direction direction);
};

#endif // GAME_HPP
