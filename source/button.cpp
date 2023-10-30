#include "../en-tete/Button.hpp"

using namespace std;
using namespace sf;

/**
 * @brief Constructeur de la classe Button.
 * 
 * @param size Taille du bouton.
 * @param text Texte à afficher sur le bouton.
 */
Button::Button(Vector2f size, Text text) {
    button.setSize(size);
    button.setFillColor(color); // Assurez-vous que "color" est correctement défini
    this->text = text;
    this->text.setCharacterSize(50);
    this->text.setFillColor(Color::Red);
    this->text.setPosition(Vector2f(0.0f, 0.0f));
}

/**
 * @brief Initialise le bouton avec une position, une police de caractères et une texture.
 * 
 * @param position Position du bouton.
 * @param font Police de caractères pour le texte.
 * @param texture Texture à afficher sur le bouton.
 */
void Button::init(Vector2f position, Font font, Texture& texture) {
    button.setPosition(position);
    this->text.setPosition(Vector2f(100.0f, 100.0f));
    this->text.setFont(font);

    // Configurez la texture du bouton et assurez-vous qu'elle est mise à l'échelle correctement
    this->sprite.setTexture(texture);
    this->sprite.setScale(button.getSize().x / texture.getSize().x, button.getSize().y / texture.getSize().y);
    
    // Positionnez la texture au centre du bouton
    this->sprite.setPosition(button.getPosition().x + (button.getSize().x - texture.getSize().x * sprite.getScale().x) / 2,
                            button.getPosition().y + (button.getSize().y - texture.getSize().y * sprite.getScale().y) / 2);
}

/**
 * @brief Change la couleur du bouton et de son texte.
 * 
 * @param color Couleur à appliquer au bouton.
 */
void Button::setColor(Color &color) {
    button.setFillColor(color);
    this->text.setFillColor(color);
}

/**
 * @brief Modifie le texte affiché sur le bouton.
 * 
 * @param text Texte à afficher sur le bouton.
 */
void Button::setText(Text text) {
    this->text.setString(text.getString()); 
}

/**
 * @brief Définit l'état pressé ou non du bouton.
 * 
 * @param pressed Booléen pour définir si le bouton est pressé.
 */
void Button::setPressed(bool pressed) {
    this->pressed = pressed;
}

/**
 * @brief Vérifie si le bouton est pressé.
 * 
 * @return True si le bouton est pressé, sinon False.
 */
bool Button::isPressed() {
    return this->pressed;
}

/**
 * @brief Obtient le texte actuellement affiché sur le bouton.
 * 
 * @return Texte affiché sur le bouton.
 */
String Button::getText() {
    return this->text.getString();
}

/**
 * @brief Obtient la position actuelle du bouton.
 * 
 * @return Position du bouton.
 */
Vector2f Button::getPosition() {
    return this->button.getPosition();
}

/**
 * @brief Obtient la taille actuelle du bouton.
 * 
 * @return Taille du bouton.
 */
Vector2f Button::getSize() {
    return this->button.getSize();
}

/**
 * @brief Obtient les limites globales du bouton.
 * 
 * @return Limites globales du bouton.
 */
FloatRect Button::getGlobalBounds() {
    // Obtenez les limites globales du bouton
    FloatRect bounds = this->button.getGlobalBounds();
    return bounds;
}

/**
 * @brief Dessine le bouton, son texte et sa texture.
 * 
 * @param target Cible de rendu.
 * @param states État de rendu.
 */
void Button::draw(RenderTarget& target, RenderStates states) const {
    // Dessinez le bouton, le texte et la texture
    target.draw(this->button, states); 
    target.draw(this->text, states);   
    target.draw(this->sprite, states);
}

/**
 * @brief Positionne le texte au centre du bouton.
 * 
 * @param text Texte à positionner au centre du bouton.
 */
void Button::setTextPosition(Text &text) {
    // Obtenir les dimensions du bouton (qui est un RectangleShape)
    FloatRect buttonBounds = button.getGlobalBounds();

    // Obtenir les dimensions du texte
    FloatRect textBounds = text.getLocalBounds();

    // Calculer la position x pour centrer le texte horizontalement
    float x = (buttonBounds.width - textBounds.width) / 2.0f;

    // Calculer la position y pour centrer le texte verticalement
    float y = (buttonBounds.height - textBounds.height) / 2.0f;

    // Définir la nouvelle position du texte en fonction de la position du bouton
    text.setPosition(button.getPosition().x + x, button.getPosition().y + y);
}
