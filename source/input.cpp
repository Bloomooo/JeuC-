#include "../en-tete/Input.hpp"

Input::Input(){
    button.left = false;
    button.right = false;
    button.up = false;
    button.down = false;
    button.attack = false;
    button.escape = false;
}

Input::Button Input::getButton(){
    return button;
}

void Input::eventListener(Event event, RenderWindow& window) {

    if (event.type == Event::Closed){
        window.close();
    }
    if (event.type == Event::KeyPressed){
        if(event.key.code == Keyboard::Escape){
            button.escape = true;
        }
        if(event.key.code == Keyboard::Z){
            button.up = true;
        }
        if(event.key.code == Keyboard::S){
            button.down = true;
        }
        if(event.key.code == Keyboard::Q){
            button.left = true;
        }
        if(event.key.code == Keyboard::D){
            button.right = true;
        }

    }
    if (event.type == Event::KeyReleased){
        if(event.key.code == Keyboard::Escape){
            button.escape = false;
        }
        if(event.key.code == Keyboard::Z){
            button.up = false;
        }
        if(event.key.code == Keyboard::S){
            button.down = false;
        }
        if(event.key.code == Keyboard::Q){
            button.left = false;
        }
        if(event.key.code == Keyboard::D){
            button.right = false;
        }
    }
    if (event.type == Event::MouseButtonPressed){
        if(event.mouseButton.button == Mouse::Left){
            button.attack = true;
        }
    }
    if (event.type == Event::MouseButtonReleased){
        if(event.mouseButton.button == Mouse::Left){
            button.attack = false;
        }
    }
}