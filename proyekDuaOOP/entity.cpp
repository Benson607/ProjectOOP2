#include "entity.h"

Entity* attacker;
Entity* choosen;

namespace Skill {
	int attackDice = 1;
	int provokeDice = 1;
	int sbDice = 3;
	int healDice = 2;
	int suDice = 2;
	void hand() {
		choosen->vitality--;
	}
	void weaponAttack() {
		choosen->vitality--;
	}
	void provoke() {
	}
	void shock_blast() {

	}
	void heal() {

	}
	void speedUp() {

	}
}

std::string itos(int x) {
	if (x == 0) {
		return "0";
	}
	std::string ans = "";
	while (x) {
		ans.insert(ans.begin(), x % 10 + 48);
		x /= 10;
	}
	return ans;
}

Entity::Entity(int type, std::string name) : Stat(), name(name) {
	xDraw = 0;
	yDraw = 0;
	rect = Rect(type);
	inAction = 0;
	actionTimes = -1;
	addActionTimes();
	att = Skill::hand;
	pro = NULL;
	sb = NULL;
	hl = NULL;
	su = NULL;
	CD = std::vector<int>(5, -1);
	buff = std::vector<int>(4, -1);
	equip = std::vector<Equipment>(3);
}

Entity::~Entity() {
}

void Entity::setName(std::string name) {
	this->name = name;
}

std::vector<std::string> Entity::output() {
	std::vector<std::string> out = { name, "vitality:", "focus:", "speed:", "hitRate:", "pAttack:", "mAttack:", "pDefense:", "mDefense:" };
	for (int i = 1; i < 9; i++) {
		out[i] = out[i] + itos((int)(this[0][i - 1]));
	}
	return out;
}

void Entity::addActionTimes() {
	actionTimes++;
	priority = (int)(((double)actionTimes + 1) / (double)speed * 100.00);
}
void Entity::setPosDraw(int x, int y) {
	xDraw = x;
	yDraw = y;
}

bool Entity::cmp(Entity other) {
	if (priority < other.priority) {
		return true;
	}
	else if (priority == other.priority) {
		if (speed > other.speed) {
			return true;
		}
		else if (speed < other.speed) {
			return false;
		}
		else if (pAttack + mAttack > other.pAttack + other.mAttack) {
			return true;
		}
		else if (pAttack + mAttack < other.pAttack + other.mAttack) {
			return false;
		}
		else if (pDefense + mDefense > other.pDefense + other.mDefense) {
			return true;
		}
		else if (pDefense + mDefense < other.pDefense + other.mDefense) {
			return false;
		}
		else if (vitality > other.vitality) {
			return true;
		}
		else if (vitality < other.vitality) {
			return false;
		}
	}
	return false;
}

bool Entity::actionForFight(Entity& enemy) {
	int input = -1;
	std::vector<std::string> fleeCheck = {
		"------------------------------",
		"| You sure you want to flee? |",
		"|                            |",
		"|       YES         NO       |",
		"|      enter        esc      |",
		"------------------------------"
	};
	std::vector<std::string> focusCheck = {
		"------------------------------",
		"|     Enter fucus amount     |",
		"|                            |",
		"|                            |",
		"|                            |",
		"|           enter            |",
		"------------------------------"
	};
	std::vector<std::string> temp;
	bool actionEnd = false;
	while (!actionEnd) {
		input = _getch();
		if (input == 27) {//esc
			temp = Draw::readSpace(64, 18, 6, 30);
			Draw::draw(fleeCheck, 64, 18);
			do {
				input = _getch();
				if (input == 'y') {
					Draw::draw(temp, 64, 18);
					attacker = NULL;
					choosen = NULL;
					return true;
				}
			} while (input != 13 && input != 27);
			Draw::draw(temp, 64, 18);
		}
		if (input == '1') {
			temp = Draw::readSpace(64, 18, 7, 30);
			std::string num = "";
			int keep = 0;;
			int number = 0;
			do {
				Draw::draw(focusCheck, 64, 18);
				std::string numberStr = itos(number) + "/3";
				Draw::gotoxy(78 - numberStr.length() / 2, 21);
				std::cout << numberStr;
				input = _getch();
				if (input >= '0' && input <= '9' && number<=100000000) {
					number *= 10;
					number += input - '0';
				}
				else if (input == 8) {
					number /= 10;
				}
				else if (input == 13) {
					if (number <= focus) {
						Draw::draw(temp, 64, 18);
						break;
					}
				}
			} while (1);
			Dice dice;
			dice.attack(*this, number, Skill::attackDice, hitrate);
			choosen = &enemy;
			att();
			actionEnd = true;
		}
		else if (input == '2') {

		}
		else if (input == '3') {

		}
		else if (input == '4') {

		}
		else if (input == '5') {

		}
	}
	attacker = NULL;
	choosen = NULL;
	return false;
}

void Entity::action() {
	addActionTimes();
	for (int& i : CD) {
		if (i > 0) {
			i--;
		}
	}
	for (int& i : buff) {
		if (i > 0) {
			i--;
		}
	}
}

void Entity::use(Equipment equipment) {
	*this += equipment.status;
	takeOff(equipment.type);
	equip[equipment.type] = equipment;
	if (equipment.name == "MagicWand" || equipment.name == "RitualSword") {
		att = Skill::weaponAttack;
	}
	for (std::string i : equipment.skills) {
		if (i == "Provoke") {
			pro = Skill::provoke;
			CD[provoke] = 0;
		}
		else if (i == "Shock-Blast") {
			sb = Skill::shock_blast;
			CD[shock_blast] = 0;
		}
		else if (i == "Heal") {
			pro = Skill::heal;
			CD[heal] = 0;
		}
		else if (i == "SpeedUp") {
			pro = Skill::speedUp;
			CD[speedUp] = 0;
		}
	}
}

void Entity::takeOff(int type) {
	if (equip[type].name == "MagicWand" || equip[type].name == "RitualSword") {
		att = Skill::hand;
	}
	*this -= equip[type].status;
	for (std::string i : equip[type].skills) {
		if (i == "Provoke") {
			pro = NULL;
			CD[provoke] = -1;
		}
		else if (i == "Shock-Blast") {
			sb = NULL;
			CD[shock_blast] = -1;
		}
		else if (i == "Heal") {
			pro = NULL;
			CD[heal] = -1;
		}
		else if (i == "SpeedUp") {
			pro = NULL;
			CD[speedUp] = -1;
		}
	}
	equip[type] = Equipment();
}

void Entity::use(Item item) {

}

bool Entity::flee()
{
	return false;
}
