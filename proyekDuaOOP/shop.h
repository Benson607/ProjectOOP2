#pragma once
#include <conio.h>
#include <string>
#include <vector>
#include "rect.h"
#include "bag.h"
#include "money.h"
#include "equipment.h"
#include "item.h"

class Shop {
public:
	//Map map;
	int pos_x;
	int pos_y;
	int buying;
	Rect rect;
	Shop();
	void select_item();
	int get_x();
	int get_y();
	std::vector<std::string> shop_ui;
};