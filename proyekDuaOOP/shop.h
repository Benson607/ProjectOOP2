#pragma once
#include <conio.h>
#include <string>
#include <vector>
#include "rect.h"
#include "bag.h"
#include "money.h"
#include "equipment.h"
#include "item.h"
#include "draw.h"

using namespace Draw;

class Shop {
public:
	Shop();
	int pos_x;
	int pos_y;
	int buying;
	Rect rect;
	std::vector<Item> items;
	std::vector<Equipment> equit;
	std::vector<int> price;
	void select_product();
	int get_x();
	int get_y();
	void random_products();
	std::vector<std::string> shop_ui;
};