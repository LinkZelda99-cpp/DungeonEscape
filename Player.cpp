#include "Player.h"
#include <iostream>


void Player::showStats() {

    std::cout << "\n------ STATS ------\n";
    std::cout << "Health: " << health << "\n";
    std::cout << "Gold: " << gold << "\n";
    std::cout << "-------------------\n";

}