#pragma once

#include <conio.h>

#include "bag.h"
#include "dice.h"

using ptr = void(*)();

class Entity : public Stat {
private:
	int priority;

	enum {
		run,
		hammer_splash,
		destroy,
		laurelWreath,
	};

	enum {
		provoke,
		shock_blast,
		heal,
		speedUp,
		fortify
	};

	enum {
		angry,
		dizziness,
		poisoned,
	};

	std::vector<std::string> introduce;

public:
	static std::vector<std::vector<Rect>>* map;

	ptr att;
	ptr pro;
	ptr sb;
	ptr hl;
	ptr su;

	bool teleportScroll;

	std::vector<bool> passive;
	std::vector<int> CD;
	std::vector<int> buff;

	int attackDice;
	int fleeDice;
	int provokeDice;
	int sbDice;
	int healDice;
	int suDice;

	int useFocus;

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

	std::vector<std::string> output();

	void mainPhaseStart();
	void addActionTimes();
	bool actionForFight(Entity& enemy);
	bool actionForEnemy(Entity& role);
	bool askFocus(int numOfDice);

	bool cmp(Entity other);
	void setName(std::string name);
	void setPosDraw(int x, int y);

	void use(Equipment equipment);
	void use(Item item);
	void takeOff(int type);
	void checkDice();
};