#pragma once

#include "item.h"
#include "equipment.h"
#include "money.h"
#include <vector>

class Bag {
public:
	static std::vector<Equipment> equipments;
	static std::vector<Item> items;
	Bag();
};