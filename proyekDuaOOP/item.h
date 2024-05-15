#pragma once

#include <string>
#include <vector>

#include "stat.h"

class Item {
public:
	Item();
	Item(std::string name);
	std::string name;
	Stat status;
	std::vector<std::string> item_names;
	void use_items(Stat& target, int kind);
};