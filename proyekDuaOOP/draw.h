#ifndef DRAW_H
#define DRAW_H

#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>

#include "rect.h"

namespace Draw {
	void draw(std::vector<std::string> out, int x, int y);
	void drawMap(std::vector<std::vector<Rect>> map, int fromx, int fromy, int x = 2, int y = 2, int sizex = 25, int sizey = 50);
	void gotoxy(int x, int y);
	void inRange();
	void setColor(int color = 7);
	std::string read(int x, int y, DWORD len);
	std::vector<std::string> readSpace(int x, int y, int high, DWORD len);
};  // namespace Draw

#endif  // !DRAW_H
