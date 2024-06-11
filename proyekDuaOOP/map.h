#pragma once

#include "entity.h"
#include "draw.h"
#include "rect.h"
#include <vector>
#include <iostream>
#include <Windows.h>

class Map :public std::vector<std::vector<Rect>> {
public:
	int nowx = 0;
	int nowy = 0;
	int stay_tent_x = -1;
	int stay_tent_y = -1;
	bool end_game = 0;
	Map();
	void setRect(Rect& obj);
	void setWall();
	void setShop();
	void setEvent();
	void set_new_rect_type(int x, int y, char T);
	void getinput(Entity& entity, int player, std::vector<Entity*>& stay);

	void show();
};