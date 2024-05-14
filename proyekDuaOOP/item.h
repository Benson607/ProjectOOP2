#pragma once

#include "stat.h"
#include <string>
#include <vector>

class Item {
public:
	Item();
	Item(std::string name);
	std::string name;
	Stat status;
	std::vector<std::string> item_names;
	void use_items(Stat& target, int kind);
};