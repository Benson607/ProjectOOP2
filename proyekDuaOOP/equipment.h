#pragma once

#include <string>
#include "stat.h"

class Equipment {
public:
	Equipment();
	Stat status;
	void Weapon(std::string kind);
	void Armour(int kind);
	void Accessory(int kind);
};