#pragma once

#include "draw.h"
#include "rect.h"
#include <vector>
#include <iostream>
#include <Windows.h>

class Map:public std::vector<std::vector<Rect>> {
public:
	int nowx = 0;
	int nowy = 0;
	Map();
	void setRect(Rect& obj);
	void setWall();
	void show();
	void getinput(int player);
};