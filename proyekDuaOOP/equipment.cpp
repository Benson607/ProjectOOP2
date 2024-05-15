#include "equipment.h"

Equipment::Equipment()
{
}

void Equipment::Weapon(std::string kind)
{
	if (kind == "WoodenSword") {
		status[4] += 5;
		status[3] += 5;
	}
}
