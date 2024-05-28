#pragma once

#include <string>
#include <vector>
#include <conio.h>

#include "item.h"
#include "rect.h"
#include "stat.h"
#include "draw.h"

using ptr = void(*)();

class Entity : public Stat {
private:
	int priority;
	std::vector<int> CD;
public:
	int xDraw;
	int yDraw;
	ptr att;
	ptr pro;
	ptr sb;
	ptr hl;
	ptr su;
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
	enum {
		provoke,
		shock_blast,
		heal,
		speedUp
	};
};