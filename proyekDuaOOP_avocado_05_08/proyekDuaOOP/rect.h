#pragma once

#include <stdlib.h>

class Rect {
public:
	int x;
	int y;
	char type;
	Rect();
	Rect(int type);
	void setRandomPos();
};