#pragma once

#include <string>
#include <vector>

#include "stat.h"

class Item {
public:
	Item(std::string name = "");
	int price;
	int amount;
	std::string name;
	Stat status;
	std::vector<std::string> item_names;
	void GoldenRoot();
	void Godsbeard();
	void TeleportScroll();
	void Tent();
};
