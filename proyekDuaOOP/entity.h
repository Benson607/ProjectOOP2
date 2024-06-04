#pragma once

#include <conio.h>

#include "bag.h"
#include "dice.h"

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
	int attackDice;
	int provokeDice;
	int sbDice;
	int healDice;
	int suDice;
	
	int xDraw;
	int yDraw;
	
	std::vector<Equipment> equip;
	
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
	bool actionForFight(Entity& enemy);
	void action();
	void use(Equipment equipment);
	void takeOff(int type);
	void use(Item item);

};