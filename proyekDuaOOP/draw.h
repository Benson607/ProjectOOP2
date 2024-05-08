#ifndef DRAW_H
#define DRAW_H

#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include "Rect.h"

namespace Draw {
	void draw(std::vector<std::string> out, int x, int y);
	void drawMap(std::vector<std::vector<Rect>> map, int fromx, int fromy, int x = 0, int y = 0, int sizex = 40, int sizey = 50);
	void gotoxy(int x, int y);
	void inRange();
	void setColor(int color = 7);
};

#endif // !DRAW_H
