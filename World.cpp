#include "World.h"
#include "Battle.h"

#include <iostream>
#include <limits>


void explore(Player& player) {

    std::cout << "You decide you should look around. Where do you want to go?\n";
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
        std::cout << "Hesitantly, you enter the dark cave. Your footsteps echo off the walls and bounce back to you. There are also other sounds. Is that? No, it can’t be something else. You must be imagining it. But you can’t help but wonder if you’re really alone.\n";
        int diceRoll = randint(1, 5);
        if (diceRoll == 2) {
            std::cout << "Something shiny catches your eye. You walk over and pick it up. It’s a rusty sword with one stubborn spot that remains shiny. You picked up the Stubborn Sword. (You can now view the Stubborn Sword from your inventory)";
            player.addItem(Item(200, "Stubborn Sword", "A rusty sword with one stubborn shiny spot.", false));
        }
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
