#ifndef DRAW_H
#define DRAW_H

#include <Windows.h>

#include <iostream>
#include <string>
#include <vector>

#include "Rect.h"

namespace Draw {
void draw(std::vector<std::string> out, int x, int y);
void drawMap(std::vector<std::vector<Rect>> map, int fromx, int fromy, int x = 0, int y = 0, int sizex = 40, int sizey = 50);
void gotoxy(int x, int y);
void inRange();
void setColor(int color = 7);
};  // namespace Draw

#endif  // !DRAW_H
