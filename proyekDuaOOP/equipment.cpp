
#include "equipment.h"

Equipment::Equipment() {
	numOfDice = -1;
	name = "";
	type = -1;
	price = 0;
	amount = 0;
	skills = std::vector<std::string>(0);
	status = Stat(0);
}

void Equipment::Weapon(std::string kind) {
	type = 0;
	name = kind;
	price = 50;
	if (kind == "WoodenSword") {
		status[4] = 5;
		status[3] = 10;
		amount = 2;
		skills.push_back("SpeedUp");
		numOfDice = 3;
	}
	else if (kind == "Hammer") {
		status[4] = 15;
		status[3] = -15;
		amount = 1;
		skills.push_back("Hammer-Splash");
		skills.push_back("Provoke");
		numOfDice = 4;
	}
	else if (kind == "GiantHammer") {
		status[4] = 20;
		status[3] = -15;
		amount = 3;
		skills.push_back("Hammer-Splash");
		numOfDice = 5;
	}
	else if (kind == "MagicWand") {
		status[5] = 10;
		amount = 1;
		skills.push_back("Shock-Blast");
		skills.push_back("Heal");
		numOfDice = 3;
	}
	else if (kind == "RitualSword") {
		status[5] = 15;
		amount = 1;
		skills.push_back("Shock-Blast");
		numOfDice = 1;
	}
}

void Equipment::Armour(std::string kind)
{
	type = 1;
	name = kind;
	price = 45;
	if (kind == "WoodenShield") {
		status[6] = 10;
		amount = 1;
		skills.push_back("Provoke");
	}
	else if (kind == "PlateArmor") {
		status[6] = 20;
		status[2] = -10;
		amount = 2;
		skills.push_back("Fortify");
	}
	else if (kind == "LeatherArmor") {
		status[6] = 5;
		amount = 1;
		skills.push_back("Fortify");
	}
	else if (kind == "Robe") {
		status[7] = 10;
		amount = 1;
	}
	else if (kind == "LaurelWreath") {
		amount = 2;
	}
}

void Equipment::Accessory(std::string kind)
{
	type = 2;
	name = kind;
	price = 30;
	if (kind == "HolyGrail") {
		status[7] = 30;
		skills.push_back("Heal");
		amount = 1;
	}
	else if (kind == "Shoes") {
		status[2] = 5;
		skills.push_back("Run");
		amount = 3;
	}
	else if (kind == "Bracelet") {
		status.focus_max = 1;
		amount = 1;
	}
}

