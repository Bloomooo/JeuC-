#include "../en-tete/Main.hpp"
#include "../en-tete/Input.hpp"
#include "../en-tete/Button.hpp"
#include "../en-tete/Menu.hpp"

Menu menu;

int main(){
    try {
        menu.lunchGame();
    } catch (const exception& e) {
        cerr << "An exception occurred: " << e.what() << endl;
    } catch (...) {
        cerr << "An unknown exception occurred." << endl;
    }
    return 0;
}