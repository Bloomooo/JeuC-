#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include "../en-tete/Button.hpp"
#include "../en-tete/Game.hpp"
#include "../en-tete/GameState.hpp"
#include "../en-tete/Input.hpp"

using namespace std;
using namespace sf;

/**
 * @class Menu
 * @brief Gère le menu principal du jeu.
 */
class Menu {
public:
    /**
     * @brief Constructeur de Menu.
     */
    Menu();

    /**
     * @brief Lance le jeu principal.
     */
    void lunchGame();

    /**
     * @brief Charge la police de caractères.
     */
    void loadFont();

    /**
     * @brief Charge les textures pour les éléments du menu.
     */
    void loadTexture();

    /**
     * @brief Définit le texte d'un élément graphique.
     * @param text L'objet Text à modifier.
     * @param chaine La chaîne de caractères à afficher.
     */
    void setText(Text &text, string chaine);

    void setTextTitle(Text &text, string chaine);

    /**
     * @brief Affiche les éléments du menu dans la fenêtre.
     * @param window La fenêtre de rendu.
     */
    void windowDraw(RenderWindow& window);

    /**
     * @brief Redimentionne le background à la taille de la fenêtre.
    */
    void rediBackground();

    void changeGameState(GameState newState);

    void checkKeyState();

private:
    Texture backgroundTexture;
    Sprite backgroundSprite;
    bool active = true;
};

#endif // !MENU_HPP
