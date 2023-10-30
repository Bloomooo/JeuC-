#include "../en-tete/Button.hpp"

using namespace std;
using namespace sf;

Button::Button(Vector2f size, Text text){
    button.setSize(size); 
    button.setFillColor(color);
    this->text = text;
    this->text.setCharacterSize(50);
    this->text.setFillColor(Color::Red);
    this->text.setPosition(Vector2f(0.0f, 0.0f));
}

void Button::init(Vector2f position, Font font, Texture& texture){
    button.setPosition(position);
    this->text.setPosition(Vector2f(100.0f, 100.0f));
    this->text.setFont(font);
    this->sprite.setTexture(texture);
    this->sprite.setScale(button.getSize().x / texture.getSize().x, button.getSize().y / texture.getSize().y);
    
    // Positionnez la texture au centre du bouton
    this->sprite.setPosition(button.getPosition().x + (button.getSize().x - texture.getSize().x * sprite.getScale().x) / 2,
                            button.getPosition().y + (button.getSize().y - texture.getSize().y * sprite.getScale().y) / 2);
}

void Button::setColor(Color &color){
    button.setFillColor(color);
    this->text.setFillColor(color);
}

void Button::setText(Text text){
    this->text.setString(text.getString()); 
}
void Button::setPressed(bool pressed){
    this->pressed = pressed;
}

bool Button::isPressed(){
    return this->pressed;
}

String Button::getText(){
    return this->text.getString();
}   

Vector2f Button::getPosition(){
    return this->button.getPosition();
}

void Button::draw(RenderTarget& target, RenderStates states) const {
    target.draw(this->button, states); 
    target.draw(this->text, states);   
    target.draw(this->sprite, states);
}

void Button::setTextPosition(Text &text) {
    // Obtenir les dimensions du bouton (qui est un RectangleShape)
    FloatRect buttonBounds = button.getLocalBounds();

    // Obtenir les dimensions du texte
    FloatRect textBounds = text.getLocalBounds();

    // Calculer la position x pour centrer le texte horizontalement
    float x = (buttonBounds.width - textBounds.width) / 2.0f;

    // Calculer la position y pour centrer le texte verticalement
    float y = (buttonBounds.height - textBounds.height) / 2.0f;

    // Définir la nouvelle position du texte en fonction de la position du bouton
    text.setPosition(button.getPosition().x+ x, button.getPosition().y+ y);
}