#include "item.h"

Item::Item() {
	status.vitality = 0;
	status.focus = 0;
	item_names = std::vector<std::string>(4);
}

Item::Item(std::string name) {
	this->name = name;
	if (name == "Godsbeard") {
		status.vitality = 25;
	}
	else if (name == "GoldenRoot") {
		status.focus = 3;
	}
	else if (name == "TeleportScroll") {

	}
	else if (name == "Tent") {

	}
}

void Item::use_items(Stat& target, int kind) {
	switch (kind)
	{
	case 0://Godsbeard
		status.vitality = 25;
		break;
	case 1://GoldenRoot
		status.focus = 3;
		break;
	case 2://TeleportScroll

		break;
	case 3://Tent
		status.vitality = 50;
		status.focus = 5;
		break;
	default:
		break;
	}
	target += status;
}
