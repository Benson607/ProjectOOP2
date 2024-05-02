#pragma once

#include "rect.h"
#include <vector>
#include <iostream>

class Map:public std::vector<std::vector<Rect>> {
public:
	Map();
	void setRect(Rect obj);
	void setWall();
	void show();
};