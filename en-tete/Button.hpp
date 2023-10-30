#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Button : public Drawable, public Transformable{
public:
    Button(Vector2f size, Text text);
    void init(Vector2f position, Font font, Texture& texture);
    bool isPressed();
    void setPressed(bool pressed);
    void setColor(Color& color);
    void setText(Text text);
    String getText();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    Vector2f getPosition();
    void setTextPosition(Text &text);

private:
    RectangleShape button;
    Vector2f position;
    Vector2f size;
    Text text;
    Color color = Color::White;
    FloatRect textRect;
    bool pressed;
    Sprite sprite;
};

#endif // !BUTTON_HPP
