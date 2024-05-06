#pragma once
#include <conio.h>
#include <string>
#include <vector>
#include "Map.h"
#include "bag.h"

class Shop {
public:
	//Map map;
	int pos_x;
	int pos_y;
	int buying;
	char icon;
	Shop();
	void select_item();
	int get_x();
	int get_y();
	std::vector<std::string> shop_ui;
};