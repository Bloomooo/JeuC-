#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

/**
 * @class Button
 * @brief Représente un bouton interactif avec du texte et une image.
 */
class Button : public Drawable, public Transformable {
public:
    /**
     * @brief Constructeur de Button.
     * @param size La taille du bouton.
     * @param text Le texte à afficher sur le bouton.
     */
    Button(Vector2f size, Text text);

    /**
     * @brief Initialise le bouton avec une position, une police de caractères et une texture.
     * @param position La position du bouton.
     * @param font La police de caractères pour le texte.
     * @param texture La texture à afficher sur le bouton.
     */
    void init(Vector2f position, Font font, Texture& texture);

    /**
     * @brief Vérifie si le bouton est enfoncé.
     * @return Vrai si le bouton est enfoncé, sinon faux.
     */
    bool isPressed();

    /**
     * @brief Définit l'état enfoncé ou relâché du bouton.
     * @param pressed Vrai pour enfoncé, faux pour relâché.
     */
    void setPressed(bool pressed);

    /**
     * @brief Définit la couleur du bouton et du texte.
     * @param color La couleur à appliquer.
     */
    void setColor(Color& color);

    /**
     * @brief Définit le texte à afficher sur le bouton.
     * @param text Le texte à afficher.
     */
    void setText(Text text);

    /**
     * @brief Récupère le texte actuellement affiché sur le bouton.
     * @return Le texte du bouton.
     */
    String getText();

    /**
     * @brief Récupère la position actuelle du bouton.
     * @return La position du bouton.
     */
    Vector2f getPosition();

    /**
     * @brief Définit la position du texte pour le centrer sur le bouton.
     * @param text Le texte à positionner.
     */
    void setTextPosition(Text &text);

    /**
     * @brief Redéfinition de la fonction de dessin.
     *
     * Cette fonction est utilisée pour dessiner l'objet graphique sur une cible (par exemple, une fenêtre) en utilisant les états de rendu spécifiés.
     * Elle doit être redéfinie dans les classes dérivées pour effectuer le dessin spécifique à l'objet.
     *
     * @param target La cible de rendu sur laquelle l'objet doit être dessiné.
     * @param states Les états de rendu à appliquer lors du dessin.
     */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /**
     * @brief Récupère la taille actuelle du bouton.
     * @return La taille du bouton.
     */
    Vector2f getSize();

    /**
     * @brief Récupère les limites globales du bouton.
     * @return Un rectangle représentant les limites globales du bouton.
     */
    FloatRect getGlobalBounds();

private:
    RectangleShape button; ///< Représentation graphique du bouton.
    Vector2f position; ///< Position du bouton.
    Vector2f size; ///< Taille du bouton.
    Text text; ///< Texte affiché sur le bouton.
    Color color = Color::White; ///< Couleur du bouton.
    FloatRect textRect; ///< Limites du texte.
    bool pressed; ///< État enfoncé du bouton.
    Sprite sprite; ///< Image à afficher sur le bouton.
};

#endif // !BUTTON_HPP
