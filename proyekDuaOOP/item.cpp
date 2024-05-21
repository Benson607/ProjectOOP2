#include "item.h"

Item::Item() {
	status.vitality = 0;
	status.focus = 0;
	item_names = std::vector<std::string>(4);
}

Godsbeard::Godsbeard():Item() {
	status.vitality = 25;
}

void Godsbeard::use_items(Stat& target)
{
	target += status;
}

GoldenRoot::GoldenRoot() {
	status.focus = 3;
}

void GoldenRoot::use_items(Stat& target)
{
	target += status;
}

TeleportScroll::TeleportScroll() {
	//X move x only --> enter
}

Tent::Tent() {
	status.vitality = 50;
	status.focus = 5;
}