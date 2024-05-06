#pragma once
#include "map.h"
#include "stat.h"

class Item {
public:
	Item();
	Stat status;
	void use_items(int kind);
};