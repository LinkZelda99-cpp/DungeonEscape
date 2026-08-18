#pragma once
#include <string>

class Player {

public:

    std::string name;
    int health = 100;
    int gold = 0;

    void showStats();

};