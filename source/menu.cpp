#include "../en-tete/Menu.hpp"


RenderWindow window;
VideoMode ecran;
Font* font = nullptr;
Text textStart;
Text textExit;
Input input;
int posY = 0;
int posX = 0;
//CircleShape circle(100);
ContextSettings settings;
Event event;
Button buttonStart(Vector2f(100.0f, 100.0f), textStart);
Button buttonExit(Vector2f(500.0f, 200.0f), textExit);
Texture buttonStartTexture;

Menu::Menu(){
    try {
        loadFont();
        loadTexture();
    } catch (const exception& e) {
        cerr << "An exception occurred: " << e.what() << endl;
    } catch (...) {
        cerr << "An unknown exception occurred." << endl;
    }
}

void Menu::lunchGame() {
    settings.antialiasingLevel= 8;
    ecran = VideoMode::getDesktopMode();  
    try {
        window.create(ecran, "ez", Style::Default, settings);
        loadFont();
        buttonStart.init(Vector2f(800.0f, 600.0f), *font, buttonStartTexture);
        buttonExit.init(Vector2f(100.0f, 200.0f), *font, buttonStartTexture);
        setText(textStart, "Start");
        setText(textExit, "Exit");
        buttonStart.setText(textStart);
        buttonExit.setText(textExit);
        buttonStart.setTextPosition(textStart);
        buttonExit.setTextPosition(textExit);
        //circle.setFillColor(Color::Red);
        while (window.isOpen()) {
            while (window.pollEvent(event)) {
                input.eventListener(event, window);
                //checkButton();
            }
            //textStart.setPosition(buttonStart.getPosition()+buttonStart.getPosition()/3.6f);
            //textExit.setPosition(buttonExit.getPosition()+buttonExit.getPosition()/5.0f);
            
            windowDraw(window);
        }
    } catch (const exception& e) {
        cerr << "An exception occurred: " << e.what() << endl;
    } catch (...) {
        cerr << "An unknown exception occurred." << endl;
    }
}


void Menu::loadFont(){
    font = new Font;
    if(!font->loadFromFile("ressource/poppins.ttf")){
        cout<<"Error loading font"<<endl;
        delete font;
        font = nullptr;
    }
}

void Menu::loadTexture(){
    if(!buttonStartTexture.loadFromFile("ressource/start.jpg")){
        cout <<"Error, Texture not loaded"<<endl;
    }
}
void Menu::setText(Text& texte, string chaine){
    texte.setFont(*font);
    texte.setString(chaine);
    texte.setCharacterSize(30);
    texte.setFillColor(Color::Red);
    texte.setStyle(Text::Bold | Text::Underlined);
}

/*
void Menu::checkButton(){
    if(input.getButton().left){
        posX-= 10;
        if(posX < 0){
            posX = 0;
        }
        setText(texte,to_string(posX));
        circle.setPosition(posX,posY);
    }
    else if(input.getButton().right){
        
        posX+=10;
        if(posX > static_cast<int>(ecran.width)-200){
            posX = ecran.width-200;
        }
        setText(texte,to_string(posX));
        circle.setPosition(posX,posY);
    }
    else if(input.getButton().up){
        posY-=10;
        if(posY < 0){
            posY = 0;
        }
        setText(texte,to_string(posY));
        circle.setPosition(posX,posY);
    }
    else if(input.getButton().down){
        posY+=10;
        if(posY > static_cast<int>(ecran.height)-200){
            posY = ecran.height-200;
        }
        setText(texte,to_string(posY));
        circle.setPosition(posX,posY);
    }
    else if(input.getButton().attack){
        setText(texte,"Attaquez");
    }
    else if(input.getButton().escape){
        window.close();
    }

}*/
void Menu::windowDraw(RenderWindow& window){
    
    window.clear(Color::Black);
    //window.draw(circle);
    window.draw(buttonStart);
    window.draw(buttonExit);
    window.draw(textExit);
    window.draw(textStart);
    window.display();
}

