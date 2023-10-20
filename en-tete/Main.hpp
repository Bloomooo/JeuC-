#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>

using namespace sf;
using namespace std;

void eventListener(Event event, RenderWindow& window);
void loadFont();
void setText(Text &text, string chaine);
void checkButton();