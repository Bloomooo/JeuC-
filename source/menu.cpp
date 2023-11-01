#include "../en-tete/Menu.hpp"
#include "../en-tete/Input.hpp"

RenderWindow window; ///< Fenêtre principale du jeu.
VideoMode ecran; ///< Mode vidéo pour la fenêtre.
Font* font = nullptr; ///< Pointeur vers l'objet Font pour charger la police de caractères.
Text textStart; ///< Texte pour le bouton "Start".
Text textExit; ///< Texte pour le bouton "Exit".
Input input; ///< Gestionnaire d'entrée utilisateur.
int posY = 0; ///< Position en Y.
int posX = 0; ///< Position en X.
ContextSettings settings; ///< Paramètres de contexte de la fenêtre.
Event event; ///< Événement pour la boucle principale.
Button buttonStart(Vector2f(500.0f, 200.0f), textStart); ///< Bouton "Start" avec sa position initiale.
Button buttonExit(Vector2f(500.0f, 200.0f), textExit); ///< Bouton "Exit" avec sa position initiale.
Texture buttonStartTexture; ///< Texture pour le bouton "Start".
Text titleGame;
Game game;
GameState gameState = GameState::MENU;

/**
 * @brief Constructeur de la classe Menu.
 */
Menu::Menu() {
    try {
        loadFont();
        loadTexture();
    } catch (const exception& e) {
        cerr << "An exception occurred: " << e.what() << endl;
    } catch (...) {
        cerr << "An unknown exception occurred." << endl;
    }
}

/**
 * @brief Fonction principale de l'application. Gère la boucle de jeu.
 */
void Menu::lunchGame() {
    settings.antialiasingLevel = 8;
    ecran = VideoMode::getDesktopMode();  
    try {
        window.create(ecran, "SeeleLand", Style::Fullscreen, settings);
        loadFont();
        buttonStart.init(Vector2f(960.0f-(buttonStart.getSize().x/2), 540.0f-(buttonStart.getSize().y/2)), *font, buttonStartTexture);
        buttonExit.init(Vector2f(960.0f-(buttonExit.getSize().x/2), 800.0f-(buttonExit.getSize().y/2)), *font, buttonStartTexture);
        setText(textStart, "Start");
        setText(textExit, "Exit");
        setTextTitle(titleGame, "SeeleLand");
        titleGame.setPosition(Vector2f(960.0f-(titleGame.getGlobalBounds().getSize().x/2), 100.0f-(titleGame.getGlobalBounds().getSize().y/2)));
        buttonStart.setText(textStart);
        buttonExit.setText(textExit);
        buttonStart.setTextPosition(textStart);
        buttonExit.setTextPosition(textExit);

        while (window.isOpen()) {
            while (window.pollEvent(event)) {
                window.clear();
                if(gameState == GameState::MENU){
                    windowDraw(window);
                    input.eventButton(event, &buttonStart, &buttonExit, window);
                }else if(gameState == GameState::GAME){
                   
                    if (event.type != Event::MouseMoved && event.type != Event::MouseButtonPressed && event.type != Event::MouseButtonReleased) {
                        input.eventListener(event, window);
                    }
                    checkKeyState();
                    
                    game.drawGame(window);
                }
                window.display();
            }

            
        }
    } catch (const exception& e) {
        cerr << "An exception occurred: " << e.what() << endl;
    } catch (...) {
        cerr << "An unknown exception occurred." << endl;
    }
}

/**
 * @brief Charge la police de caractères depuis un fichier.
 */
void Menu::loadFont() {
    font = new Font;
    if (!font->loadFromFile("ressource/poppins.ttf")) {
        cout << "Error loading font" << endl;
        delete font;
        font = nullptr;
    }
}

/**
 * @brief Charge une texture depuis un fichier.
 */
void Menu::loadTexture() {
    if (!buttonStartTexture.loadFromFile("ressource/background.jpg")) {
        cout <<"Error, Texture not loaded" << endl;
    }
    if(!this->backgroundTexture.loadFromFile("ressource/seele.jpg")) {
        cout << "Error, Texture not loaded" << endl;
    }
    this->backgroundTexture.setSmooth(true);
    this->backgroundTexture.setRepeated(true);
    this->backgroundSprite.setTexture(this->backgroundTexture);
}

/**
 * @brief Configure les propriétés du texte.
 * @param texte Référence vers l'objet Text.
 * @param chaine Chaîne de caractères du texte.
 */
void Menu::setText(Text& texte, string chaine) {
    texte.setFont(*font);
    texte.setString(chaine);
    texte.setCharacterSize(60);
    texte.setFillColor(Color::White);
    texte.setStyle(Text::Bold | Text::Underlined);
}

void Menu::setTextTitle(Text& texte, string chaine) {
    texte.setFont(*font);
    texte.setString(chaine);
    texte.setCharacterSize(100);
    texte.setFillColor(Color::White);
    texte.setStyle(Text::Bold);
}

/**
 * @brief Gère le dessin des éléments dans la fenêtre.
 * @param window Référence vers la fenêtre de rendu.
 */
void Menu::windowDraw(RenderWindow& window) {
    rediBackground();
    window.draw(this->backgroundSprite);
    window.draw(buttonStart);
    window.draw(buttonExit);
    window.draw(titleGame);
    window.draw(textExit);
    window.draw(textStart);
}

void Menu::rediBackground(){
    Vector2f backgroundSize = static_cast<Vector2f>(this->backgroundTexture.getSize());
    Vector2f windowSize(static_cast<float>(ecran.width), static_cast<float>(ecran.height));

    // Redimensionnez le fond pour qu'il couvre toute la fenêtre
    float scaleX = windowSize.x / backgroundSize.x;
    float scaleY = windowSize.y / backgroundSize.y;
    this->backgroundSprite.setScale(scaleX, scaleY);

    // Centrez le fond dans la fenêtre
    this->backgroundSprite.setPosition((windowSize.x - backgroundSize.x * scaleX) / 2.0f,
                                      (windowSize.y - backgroundSize.y * scaleY) / 2.0f);
}
void Menu::changeGameState(GameState newState) {
    gameState = newState;
}

void Menu::checkKeyState(){
    if(input.getKeyState().left){
        posX-=10;
        if(posX <= 0){
            posX = 0;
        }
    }
    else if (input.getKeyState().right){
        posX+=10;
        if(posX >= static_cast<int>(ecran.width)-200){
            posX = window.getSize().x;
        }
    }
    else if (input.getKeyState().up){
        posY-=10;
        if(posY <=0 ){
            posY = 0;
        }
    }
    else if(input.getKeyState().down){
        posY+=10;
        if(posY >= static_cast<int>(ecran.height)-200){
            posY = window.getSize().y;
        }
    }
    game.setTexturePos(posX, posY);
        
}