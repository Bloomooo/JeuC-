#include "../en-tete/Menu.hpp"
#include "../en-tete/Button.hpp"
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
Button buttonStart(Vector2f(100.0f, 100.0f), textStart); ///< Bouton "Start" avec sa position initiale.
Button buttonExit(Vector2f(500.0f, 200.0f), textExit); ///< Bouton "Exit" avec sa position initiale.
Texture buttonStartTexture; ///< Texture pour le bouton "Start".

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

        while (window.isOpen()) {
            while (window.pollEvent(event)) {
                input.eventListener(event, window);
                input.eventButton(event, &buttonStart, &buttonExit, window);
            }

            windowDraw(window);
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
    if (!buttonStartTexture.loadFromFile("ressource/start.jpg")) {
        cout <<"Error, Texture not loaded" << endl;
    }
}

/**
 * @brief Configure les propriétés du texte.
 * @param texte Référence vers l'objet Text.
 * @param chaine Chaîne de caractères du texte.
 */
void Menu::setText(Text& texte, string chaine) {
    texte.setFont(*font);
    texte.setString(chaine);
    texte.setCharacterSize(30);
    texte.setFillColor(Color::Red);
    texte.setStyle(Text::Bold | Text::Underlined);
}

/**
 * @brief Gère le dessin des éléments dans la fenêtre.
 * @param window Référence vers la fenêtre de rendu.
 */
void Menu::windowDraw(RenderWindow& window) {
    window.clear(Color::Black);
    window.draw(buttonStart);
    window.draw(buttonExit);
    window.draw(textExit);
    window.draw(textStart);
    window.display();
}
