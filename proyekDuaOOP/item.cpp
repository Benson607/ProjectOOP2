#include "item.h"

Item::Item(std::string name) {
	price = 0;
	amount = 0;
	this->name = name;
	item_names = std::vector<std::string>(4);
	status = Stat(0);
}

void Item::GoldenRoot()
{
	name = "GoldenRoot";
	price = 60;
	amount = 1;
	status.focus = 3;
}

void Item::Godsbeard()
{
	name = "Godsbeard";
	price = 60;
	amount = 1;
	status.vitality = 25;
}

void Item::TeleportScroll()
{
	name = "TeleportScroll";
	price = 60;
	amount = 2;
}

void Item::Tent()
{
	name = "Tent";
	price = 60;
	amount = 1;
	status.vitality = 50;
	status.focus = 5;
}