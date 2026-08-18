#include "World.h"
#include "Battle.h"

#include <iostream>
#include <limits>


void explore(Player& player) {

    std::cout << "Where do you want to go?\n";
    std::cout << "1. Dark Cave\n";
    std::cout << "2. Ancient Forest\n";
    std::cout << "3. Abandoned Castle\n";

    int choice;
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid location.\n";
        return;
    }


    switch (choice) {

    case 1:
        std::cout << "You enter the Dark Cave...\n";
        battle(player);
        break;


    case 2:
        std::cout << "You enter the Ancient Forest...\n";
        battle(player);
        break;


    case 3:
        std::cout << "You enter the Abandoned Castle...\n";
        battle(player);
        break;


    default:
        std::cout << "Invalid location.\n";
    }
}
