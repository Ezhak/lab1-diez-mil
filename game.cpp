#include "game.h"
// Prototipo de Menu, incluyendolo en CodigoMAIN.cpp este archivo deberia de ser borrado
void main_menu()
{
    std::cout << "\n██████╗ ██╗███████╗███████╗    ███╗   ███╗██╗██╗";
    std::cout << "\n██╔══██╗██║██╔════╝╚══███╔╝    ████╗ ████║██║██║";
    std::cout << "\n██║  ██║██║█████╗    ███╔╝     ██╔████╔██║██║██║";
    std::cout << "\n██║  ██║██║██╔══╝   ███╔╝      ██║╚██╔╝██║██║██║";
    std::cout << "\n██████╔╝██║███████╗███████╗    ██║ ╚═╝ ██║██║███████╗";
    std::cout << "\n╚═════╝ ╚═╝╚══════╝╚══════╝    ╚═╝     ╚═╝╚═╝╚══════╝";
    std::cout << "\n1 = Juego nuevo para un jugador";
    std::cout << "\n2 = Juego nuevo para dos jugadores";
    std::cout << "\n3 = Mostrar puntuación más alta";

    while (true) {
        int gamemode;

        std::cout << "\n\nModo de juego ? ";
        std::cin >> gamemode;
        std::cin.clear();
        std::cin.ignore(256, '\n');

        switch (gamemode) {
        case 1:
            play_singleplayer();
            break;
        case 2:
            // ...
            break;
        case 3:
            // ...
            break;
        default:
            std::cout << "El modo ingresado no es válido.";
            continue;
        }

        break;
    }
}

void play_singleplayer()
{
    std::string player1;
    int turns;

    system("cls");
    std::cout << "Nombre del jugador: ";
    std::cin >> player1;

    turns = 666;

    std::cout << "\nJugador: " << player1;
    std::cout << "\nTurnos: " << turns;
    std::cout << "\n";
}

