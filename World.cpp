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
        std::cout << "You enter the Dark Cave. The walls close in as you walk deeper into the dark, musty cave. CRACK! a stick breaks behind you. A goblin attacks you!\n";
        battle(player, 2);
        break;


    case 2:
        std::cout << "The Ancient Forest is calm... too calm that its eerie. You walk as the huge trees loom ahead of you. You wonder how you even got here in the first place. Are you even-? CRACK! Oop. You know what that is. You turn around to unsuprisingly see a Goblin.\n";
        battle(player, 2);
        break;


    case 3:
        std::cout << "The Abandoned Castle is very eerie... You hear strange noises coming from the upstairs as you walk in. You get ambusued by a goblin!\n";
        battle(player, 1);
        break;


    default:
        std::cout << "Invalid location.\n";
    }
}
