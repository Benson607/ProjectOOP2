#ifndef DRAW_H
#define DRAW_H

#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

namespace Draw {
	void draw(std::vector<std::string> out, int x, int y);
	void gotoxy(int x, int y);
	void inRange();
	void setColor(int color = 7);
};

#endif // !DRAW_H
