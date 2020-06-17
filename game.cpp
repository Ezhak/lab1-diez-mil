#include "game.h"

void main_menu(std::string* result)
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
            play_singleplayer(&result[0], &result[1]);
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

void play_singleplayer(std::string* winner, std::string* turns)
{
    std::string name;
    system("cls");
    std::cout << "Nombre del jugador: ";
    std::cin >> name;

    *winner = name;
    *turns = std::to_string(666);
}

