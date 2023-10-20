#include "../en-tete/Main.hpp"
#include "../en-tete/Input.hpp"

RenderWindow window;
VideoMode ecran;
Font font;
Text texte;
Input input;
int posY = 0;
int posX = 0;

int main() {
    ecran=  VideoMode::getDesktopMode();  
    window.create(ecran, "ez",Style::Fullscreen);
    loadFont();
    
    setText(texte,"Hello World");
    
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            input.eventListener(event, window);
            checkButton();
        }
        window.clear(Color::White);
        window.draw(texte);
        window.display();
    }
    
    return 0;
}


void loadFont(){
    if(!font.loadFromFile("ressource/poppins.ttf")){
        cout<<"Error loading font"<<endl;
    }
}

void setText(Text& texte, string chaine){
    texte.setFont(font);
    texte.setString(chaine);
    texte.setCharacterSize(30);
    texte.setFillColor(Color::Red);
    texte.setStyle(Text::Bold | Text::Underlined);
}

void checkButton(){
    if(input.getButton().left){
        setText(texte,"Gauche");
        posX--;
        if(posX < 0){
            posX = 0;
        }
    }
    else if(input.getButton().right){
        setText(texte,"Droite");
        posX++;
        if(posX > 1080){
            posX = 1080;
        }
    }
    else if(input.getButton().up){
        setText(texte,"Haut");
    }
    else if(input.getButton().down){
        setText(texte,"Bas");
    }
    else if(input.getButton().attack){
        setText(texte,"Attaquez");
    }
    else if(input.getButton().escape){
        window.close();
    }

}