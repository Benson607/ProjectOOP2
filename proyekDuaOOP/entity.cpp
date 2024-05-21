#include "entity.h"

Entity* attacker;
Entity* choosen;

namespace Skill {
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
	CD = std::vector<int>(4, -1);
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

bool Entity::actionForFight(std::vector<Entity*>& roles, std::vector<Entity*>& enemys) {
	int input = -1;
	std::vector<std::string> fleeCheck = {
		"------------------------------",
		"| You sure you want to flee? |",
		"|                            |",
		"|       YES         NO       |",
		"|        y          n        |",
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
			} while (input != 'y' && input != 'n');
			Draw::draw(temp, 64, 18);
		}
		if (input == '1') {
			int lastChoose = 0;
			int choose = 0;
			bool out = false;
			while (!out) {
				temp = Draw::readSpace(15 * lastChoose, 0, 9, 15);
				Draw::setColor();
				Draw::draw(temp, 15 * lastChoose, 0);
				temp = Draw::readSpace(15 * choose, 0, 9, 15);
				Draw::setColor(160);
				Draw::draw(temp, 15 * choose, 0);
				Draw::setColor();
				input = _getch();
				switch (input) {
				case 27:
					out = true;
					break;
				case 'a':
					if (choose > 0) {
						lastChoose = choose;
						choose--;
					}
					break;
				case 'd':
					if (choose < 2) {
						lastChoose = choose;
						choose++;
					}
					break;
				case 13://enter
					out = true;
					choosen = enemys[choose];
					att();
					actionEnd = true;
					break;
				default:
					break;
				}
			}
			temp = Draw::readSpace(15 * choose, 0, 9, 15);
			Draw::setColor();
			Draw::draw(temp, 15 * choose, 0);
		}
		else {

		}
	}
	attacker = NULL;
	choosen = NULL;
	return false;
}
