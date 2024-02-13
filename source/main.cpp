#include "../en-tete/Main.hpp"
#include "../en-tete/Input.hpp"
#include "../en-tete/Button.hpp"
#include "../en-tete/Menu.hpp"

Menu menu; ///< Instance de la classe Menu pour gérer le menu principal du jeu.

/**
 * @brief Fonction principale de l'application.
 *
 * Cette fonction initialise et lance le menu principal du jeu.
 *
 * @return Code de sortie de l'application (0 pour terminer normalement).
 */
int main() {
    try {
        menu.lunchGame(); // Lance le menu principal du jeu.
    } catch (const exception& e) {
        cerr << "An exception occurred: " << e.what() << endl;
    } catch (...) {
        cerr << "An unknown exception occurred." << endl;
    }
    return 0;
}
