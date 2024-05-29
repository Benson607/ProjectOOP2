#include "equipment.h"

Equipment::Equipment(std::string name)
{
	this->name = name;
	type = -1;
	price = 0;
	amount = 0;
	skills = std::vector<std::string>(0);
	status.focus_max = 0;
	status.hitrate_max = 0;
	status.mAttack_max = 0;
	status.mDefense_max = 0;
	status.pAttack_max = 0;
	status.pDefense_max = 0;
	status.speed_max = 0;
	status.vitality_max = 0;

	for (int i = 0; i < 8; i++)
	{
		status[i] = 0;
	}
}

void Equipment::Weapon(std::string kind)
{
	type = 0;
	name = kind;
	price = 50;
	if (kind == "WoodenSword") {
		status[4] = 5;
		status[3] = 10;
		amount = 2;
		skills.push_back("SpeedUp");
	}
	else if (kind == "Hammer") {
		status[4] = 15;
		status[3] = -15;
		amount = 1;
		skills.push_back("Hammer-Splash");
		skills.push_back("Provoke");
	}
	else if (kind == "GiantHammer") {
		status[4] = 20;
		status[3] = -15;
		amount = 3;
		skills.push_back("Hammer-Splash");
	}
	else if (kind == "MagicWand") {
		status[5] = 10;
		amount = 1;
		skills.push_back("Shock-Blast");
		skills.push_back("Heal");
	}
	else if (kind == "RitualSword") {
		status[5] = 15;
		amount = 1;
		skills.push_back("Shock-Blast");
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
		status[7] = 1.1;
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

