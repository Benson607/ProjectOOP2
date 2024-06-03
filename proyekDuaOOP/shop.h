#pragma once

#include <conio.h>

#include "bag.h"

using namespace Draw;

class Shop {
public:
	Shop();
	int pos_x;
	int pos_y;
	std::vector<Item> items;
	std::vector<Equipment> equip;
	std::vector<std::string> output;
	void select_product();
	void show();
	std::vector<std::string> shop_ui;
	std::vector<std::string> grid_ui;
	std::vector<std::string> statment;
	std::vector<int> position;
	std::vector<std::vector<int>> pos_x_y;
	std::vector<std::string> record;
	std::vector<std::string> money_stat;
};