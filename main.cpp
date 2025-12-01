#include "Game.h"
#include <iostream>
#include <string>
#include <limits>

int main()
{
    std::cout << "Welcome to Blackjack!" << std::endl;
    std::cout << "Name: ";

    std::string name;
    std::getline(std::cin, name);

    // just give a default name if empty
    if (name.empty())
    {
        name = "Player1";
    }

    Game game(name);

    char again = 'y';

    while (again == 'y' || again == 'Y')
    {
        game.play();

        std::cout << "Play again? (y/n): ";
        std::cin >> again;

        // clears input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Thanks for playing!" << std::endl;

    return 0;
}
