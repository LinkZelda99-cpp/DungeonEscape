#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "World.h"
#include "Player.h"

int loops = 0;

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Player player;

    std::cout << "Welcome to Dungeon Escape!\nWhat is your name? ";

    std::getline(std::cin, player.name);

    if (player.name.empty()) {
        player.name = "Adventurer";
    }

    std::cout << "\nWelcome, " << player.name << "!\n";
    std::cout << "----------------------\n";
    std::cout << "\033[3mThe shadows overwhelm your senses... darker, darker, yet darker.\033[0m\n";
    std::cout << "\033[3mThe darkness grows stronger... then vanishes.\033[0m\n";
    std::cout << "You are now in a place you've never been before.\n";
    std::cout << "----------------------\n";


    while (true) {
        std::cout << "\nWhat would you like to do?\n";
        std::cout << "1. Explore\n";
        std::cout << "2. View stats\n";
        std::cout << "3. Quit\n";

        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice.\n";
            continue;
        }

        switch (choice) {
        case 1:
            explore(player);
            break;

        case 2:
            player.showStats();
            break;

        case 3:
            return 0;

        default:
            std::cout << "Invalid choice.\n";
        }
    }
}
