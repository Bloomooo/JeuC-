#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include "../en-tete/Button.hpp"
#include "../en-tete/Input.hpp"
#include <SFML/Window.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

class Menu{
    
    public: 
        Menu();
        void lunchGame();
        void loadFont();
        void loadTexture();
        void setText(Text &text, string chaine);
        //void checkButton();
        void windowDraw(RenderWindow& window);
        //void textPosition();
        void centerTextInButton(Text& text, Button& button);
};

#endif // !MENU_HPP
