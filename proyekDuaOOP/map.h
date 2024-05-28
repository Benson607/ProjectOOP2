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
	void setShop();
	void setEvent();
	void show();
	void set_new_rect_type(int x,int y,char T);
	void getinput(int player, int player1_x, int player1_y, int player2_x, int player2_y, int player3_x, int player3_y);
};