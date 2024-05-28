#pragma once

#include <string>
#include <vector>
#include <conio.h>

#include "equipment.h"
#include "item.h"
#include "rect.h"
#include "stat.h"
#include "draw.h"

using ptr = void(*)();

class Entity : public Stat {
private:
	int priority;

	std::vector<int> CD;
	enum {
		provoke,
		shock_blast,
		heal,
		speedUp,
		fortify
	};

	std::vector<int> buff;
	enum {
		angry,
		dizziness,
		poisoned,
	};

	ptr att;
	ptr pro;
	ptr sb;
	ptr hl;
	ptr su;

public:
	int xDraw;
	int yDraw;
	Equipment weapon;
	Equipment armour;
	Equipment accessory;
	Rect rect;
	Rect under;
	std::string name;
	bool inAction;
	int actionTimes;
	Entity(int type, std::string name = "");
	~Entity();
	void setName(std::string name);
	std::vector<std::string> output();
	void addActionTimes();
	void setPosDraw(int x, int y);
	bool cmp(Entity other);
	bool actionForFight(std::vector<Entity*>& roles, std::vector<Entity*>& enemys);
	void action();
	void use(Equipment equipment);
	void takeOff(int type);
	void use(Item item);

};