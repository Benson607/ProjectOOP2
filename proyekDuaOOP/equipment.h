#pragma once

#include <string>
#include <vector>

#include "stat.h"

class Equipment {
public:
	Equipment();
	int type;
	int price;
	int amount;
	Stat status;
	std::string name;
	std::vector<std::string> skills;
	void Weapon(std::string kind);
	void Armour(std::string kind);
	void Accessory(std::string kind);
};