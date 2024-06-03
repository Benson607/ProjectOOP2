#pragma once

#include <iostream>

#include "draw.h"

class Map:public std::vector<std::vector<Rect>> {
public:
	int nowx = 0;
	int nowy = 0;
	Map();
	void setRect(Rect& obj);
	void setWall();
	void setShop();
	void show();
	void getinput(int player);
};