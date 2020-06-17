#include "game.h"

int main()
{
    std::string result[2];

    main_menu(result);
    std::cout << "\nGanador: " << result[0];
    std::cout << "\nTurnos: " << result[1];
    std::cout << "\n";

    return 0;
}

