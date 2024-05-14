#pragma once

#include <string>
#include <vector>
#include <conio.h>

#include "rect.h"
#include "stat.h"
#include "draw.h"

using ptr = void(*)();

class Entity : public Stat {
public:
	int xDraw;
	int yDraw;
	int priority;
	ptr attack;
	ptr flee;
	ptr provoke;
	ptr shock_blast;
	ptr heal;
	ptr speedUp;
	Rect rect;
	std::string name;
	bool inAction;
	int actionTimes;
	void* fucptr;
	Entity(int type, std::string name = "");
	~Entity();
	void setName(std::string name);
	std::vector<std::string> output();
	void addActionTimes();
	void setPosDraw(int x, int y);
	bool cmp(Entity other);
	bool actionForFight(std::vector<Entity*>& roles, std::vector<Entity*>& enemys);
};