#pragma once

#include "stat.h"

class Item {
public:
	Item();
	Stat status;
	void use_items(Stat stat, int kind);
};