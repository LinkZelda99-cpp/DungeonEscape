#pragma once
#include <string>
#include <iostream>

class Player; // forward

struct Item {
	int id = 0;
	std::string name;
	std::string description;
	bool consumable = true;

	Item() = default;
	Item(int id, const std::string& n, const std::string& d, bool consumable = true)
		: id(id), name(n), description(d), consumable(consumable) {}

	// Apply the item's effect to the player. Returns a message describing the effect.
	// If the item is consumable, caller may remove it from inventory after use.
	std::string use(Player& player) const;
};
