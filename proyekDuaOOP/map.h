#pragma once

#include "draw.h"
#include "rect.h"
#include <vector>
#include <iostream>
#include <Windows.h>

class Map:public std::vector<std::vector<Rect>> {
public:
	Map();
	void setRect(Rect obj);
	void setWall();
	void show();
};