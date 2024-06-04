#pragma once

#include <conio.h>
#include <map>

#include "item.h"
#include "equipment.h"
#include "money.h"
#include "draw.h"

class Bag {
public:
	static std::vector<Equipment> buy_in_E;
	static 	std::vector<Item> buy_in_T;
	static int pos_x;
	static int pos_y;
	Bag();
	static void bag_ui();

	static std::vector<std::string> statment;
	static std::vector<std::string> original_ui;
	static std::vector<std::string> bagUI;
	static std::vector<std::string> clear;
	static std::vector<std::vector<int>> pos_xy;
	static std::vector<int> store;//change to save position
};