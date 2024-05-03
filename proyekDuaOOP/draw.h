#ifndef DRAW_H
#define DRAW_H

#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

class Draw {
public:
	void draw(std::vector<std::string> out, int x, int y);
	void gotoxy(int x, int y);
	void inRange();
};

#endif // !DRAW_H
