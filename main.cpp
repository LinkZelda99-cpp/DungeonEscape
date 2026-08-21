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

    std::cout << "Welcome to Echoes of Shadows.\nWhat is your name? ";

    std::getline(std::cin, player.name);

    if (player.name.empty()) {
        player.name = "Adventurer";
    }

    std::cout << "\nWelcome, " << player.name << "!\n";
    std::cout << "----------------------\n";
    std::cout << "\033[3mThe shadows overwhelm your senses... darker, darker, yet darker.\033[0m\n";
    std::cout << "\033[3mThe darkness grows stronger... until suddenly, it vanishes.\033[0m\n";
    std::cout << "You find yourself somewhere you've never been before.\n";
    std::cout << "----------------------\n";

    // Example: programmatically add items to the player's inventory
    //player.addItem(Item(100, "Health Potion", "Restores 20 HP.", true));
    //player.addItem(Item(200, "Old Sword", "A rusty sword. Not consumable.", false));
    //player.showInventory();

    while (true) {
        std::cout << "You are surrounded by strange things, as if you have entered another world. Ahead of you is a dark cave. To your right are the ruins of what was once a grand castle. To your left lies a forest that looks as though it has stood there for centuries.\n\n";
        std::cout << "Where would you go in a place like this? Every path feels mysterious. Every direction feels like it hides something.\n";
        std::cout << "1. Explore\n";
        std::cout << "2. View stats\n";
        std::cout << "3. Inventory\n";
        std::cout << "4. Quit\n";

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

        case 3: {
            // Inventory menu
            while (true) {
                player.showInventory();
                std::cout << "Enter slot number (0-" << (Player::INVENTORY_SIZE - 1) << ") to select an item, or 'e' to exit: ";
                std::string input;
                std::cin >> input;
                if (input == "e" || input == "E" || input == "exit") break;
                int slot = -1;
                try {
                    slot = std::stoi(input);
                } catch (...) {
                    std::cout << "Invalid input.\n";
                    continue;
                }
                if (slot < 0 || slot >= Player::INVENTORY_SIZE) {
                    std::cout << "Invalid slot number.\n";
                    continue;
                }
                if (slot >= static_cast<int>(player.inventory.size())) {
                    std::cout << "That slot is empty.\n";
                    continue;
                }

                // Item actions
                std::cout << "Selected '" << player.inventory[slot].name << "' - choose action:\n";
                std::cout << "1. Use\n2. View description\n3. Drop\n4. Exit\n";
                int a;
                if (!(std::cin >> a)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid choice.\n";
                    continue;
                }
                if (a == 1) {
                    player.useItem(slot);
                } else if (a == 2) {
                    player.viewItem(slot);
                } else if (a == 3) {
                    player.dropItem(slot);
                } else if (a == 4) {
                    // exit inventory
                    break;
                } else {
                    std::cout << "Invalid action.\n";
                }
            }
            break;
        }

        case 4:
            return 0;

        default:
            std::cout << "Invalid choice.\n";
        }
    }
}
