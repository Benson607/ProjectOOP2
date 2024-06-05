#include "entity.h"

Entity* attacker;
Entity* choosen;

namespace Skill {
	void hand() {
		Dice dice;
		dice.attack(*attacker, attacker->useFocus, attacker->attackDice, attacker->hitrate);
		double times = 0;

		for (int i = 0; i < dice.result.size(); i++) {
			if (dice.result[i] == 'T') {
				times += 1.0;
			}
		}
		int damage = attacker->pAttack * times / (double)dice.result.size() * ((double)1.0 - choosen->pDefense / (choosen->pDefense + (double)50.0));
		Draw::gotoxy(20, 20);
		std::cout << attacker->name << " attack " << choosen->name << ": " << damage;
		choosen->vitality -= damage;
		if (choosen->vitality < 0) {
			choosen->vitality = 0;
		}
	}

	void weaponAttack() {
		Dice dice;
		dice.attack(*attacker, attacker->useFocus, attacker->attackDice, attacker->hitrate);
		double times = 0;
		for (int i = 0; i < dice.result.size(); i++) {
			if (dice.result[i] == 'T') {
				times += 1.0;
			}
		}
		int damage = attacker->mAttack * times / (double)dice.result.size() * ((double)1.0 - choosen->mDefense / (choosen->mDefense + (double)50.0));
		Draw::gotoxy(20, 20);
		std::cout << attacker->name << " attack " << choosen->name << ": " << damage;
		choosen->vitality -= damage;
		if (choosen->vitality < 0) {
			choosen->vitality = 0;
		}
	}

	void provoke() {
		Dice dice;
		dice.attack(*attacker, attacker->useFocus, attacker->provokeDice, attacker->vitality / (attacker->vitality_max + attacker->pAttack + attacker->mAttack));
		double times = 0;
		for (int i = 0; i < dice.result.size(); i++) {
			if (dice.result[i] == 'T') {
				times += 1.0;
			}
		}
		int damage = 3 * times / (double)dice.result.size() + 1;
		Draw::gotoxy(20, 20);
		std::cout << attacker->name << " shock-blast " << choosen->name << ": " << damage;
		choosen->buff[0] = damage;
		if (choosen->vitality < 0) {
			choosen->vitality = 0;
		}
		attacker->CD[0] = 3;
	}

	void shock_blast() {
		Dice dice;
		dice.attack(*attacker, attacker->useFocus, attacker->sbDice, attacker->hitrate - 5);
		double times = 0;
		for (int i = 0; i < dice.result.size(); i++) {
			if (dice.result[i] == 'T') {
				times += 1.0;
			}
		}
		int damage = attacker->mAttack * 0.5 * times / (double)dice.result.size() * ((double)1.0 - choosen->mDefense / (choosen->mDefense + (double)50.0));
		Draw::gotoxy(20, 20);
		std::cout << attacker->name << " shock-blast " << choosen->name << ": " << damage;
		choosen->vitality -= damage;
		if (choosen->vitality < 0) {
			choosen->vitality = 0;
		}
		attacker->CD[1] = 2;
	}

	void heal() {
		Dice dice;
		dice.attack(*attacker, attacker->useFocus, attacker->healDice, attacker->hitrate - 5);
		double times = 0;
		for (int i = 0; i < dice.result.size(); i++) {
			if (dice.result[i] == 'T') {
				times += 1.0;
			}
		}
		int damage = attacker->mAttack * 1.5 * times / (double)dice.result.size();
		attacker->vitality += damage;
		Draw::gotoxy(20, 20);
		std::cout << attacker->name << " heal himself: " << damage;
		if (choosen->vitality < 0) {
			choosen->vitality = 0;
		}
		attacker->CD[2] = 2;
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

Entity::Entity(int type, std::string name) :Stat(), name(name) {
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

	attackDice = 1;
	fleeDice = 1;
	provokeDice = 1;
	sbDice = 3;
	healDice = 2;
	suDice = 2;

	CD = std::vector<int>(5, -1);
	buff = std::vector<int>(4, 0);
	equip = std::vector<Equipment>(3, Equipment());
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
	attacker = this;
	choosen = &enemy;
	int input = -1;
	std::vector<std::string> fleeCheck = {
		"------------------------------",
		"| You sure you want to flee? |",
		"|                            |",
		"|       YES         NO       |",
		"|      enter        esc      |",
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
				if (input == 13) {
					Draw::draw(temp, 64, 18);
					attacker = NULL;
					choosen = NULL;
					return true;
				}
			} while (input != 13 && input != 27);
			Draw::draw(temp, 64, 18);
		}
		if (input == '1') {
			if (askFocus()) {
				actionEnd = true;
				att();
				useFocus = 0;
			}
			else {
				actionEnd = false;
			}
		}
		else if (input == '2') {
			if (CD[provoke] == 0) {

				CD[provoke] = 2;
			}
		}
		else if (input == '3') {
			if (CD[shock_blast] == 0) {

			}
		}
		else if (input == '4') {
			if (CD[heal] == 0) {

			}
		}
		else if (input == '5') {
			if (CD[speedUp] == 0) {

			}
		}
		else if (input == 'i') {

		}
	}
	attacker = NULL;
	choosen = NULL;
	return false;
}

bool Entity::actionForEnemy(Entity& role) {
	attacker = this;
	choosen = &role;
	int needFlee = rand() % 100;
	if (needFlee < 5) {
		Dice dice;
		double possible = vitality / (pDefense + mDefense) * speed;
		if (possible > 98) {
			possible = 98;
		}
		dice.attack(*this, 0, 1, possible / 100);
		if (dice.result[0] == 'T') {
			return true;
		}
	}
	else {
		att();
	}
	return false;
}

bool Entity::askFocus() {
	std::vector<std::string> focusCheck = {
		"------------------------------",
		"|     Enter fucus amount     |",
		"|                            |",
		"|                            |",
		"|       You have:            |",
		"|           enter            |",
		"------------------------------"
	};
	std::vector<std::string> temp = Draw::readSpace(64, 18, 7, 30);
	std::string num = "";
	useFocus = 0;
	int input = -1;
	do {
		Draw::draw(focusCheck, 64, 18);
		Draw::gotoxy(81, 22);
		std::cout << focus;
		std::string numberStr = itos(useFocus) + "/" + itos(attackDice);
		Draw::gotoxy(78 - numberStr.length() / 2, 21);
		std::cout << numberStr;
		input = _getch();
		if (input >= '0' && input <= '9' && useFocus <= 100000000) {
			useFocus *= 10;
			useFocus += input - '0';
		}
		else if (input == 8) {
			useFocus /= 10;
		}
		else if (input == 13) {
			if (useFocus <= focus && useFocus <= attackDice) {
				Draw::draw(temp, 64, 18);
				return true;
				break;
			}
		}
		else if (input == 27) {
			break;
		}
	} while (1);
	Draw::draw(temp, 64, 18);
	return false;
}

void Entity::mainPhaseStart() {
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
	addActionTimes();
}

void Entity::use(Equipment equipment) {
	*this += equipment.status;
	takeOff(equipment.type);
	equip[equipment.type] = equipment;
	if (equipment.name == "MagicWand" || equipment.name == "RitualSword") {
		att = Skill::weaponAttack;
	}
	if (equipment.name == "LaurelWreath") {
		mDefense *= 1.1;
	}
	for (std::string i : equipment.skills) {
		if (i == "Provoke") {
			pro = Skill::provoke;
			CD[provoke] = 0;
			if (equipment.numOfDice == -1) {
				provokeDice = 1;
			}
			else {
				provokeDice = equipment.numOfDice;
			}
		}
		else if (i == "Shock-Blast") {
			sb = Skill::shock_blast;
			CD[shock_blast] = 0;
			if (equipment.numOfDice == -1) {
				sbDice = 3;
			}
			else {
				sbDice = equipment.numOfDice;
			}
		}
		else if (i == "Heal") {
			pro = Skill::heal;
			CD[heal] = 0;
			if (equipment.numOfDice == -1) {
				healDice = 2;
			}
			else {
				healDice = equipment.numOfDice;
			}
		}
		else if (i == "SpeedUp") {
			pro = Skill::speedUp;
			CD[speedUp] = 0;
			if (equipment.numOfDice == -1) {
				suDice = 2;
			}
			else {
				suDice = equipment.numOfDice;
			}
		}
	}
	if (equip[1].name == "WoodenShield") {
		provokeDice = 1;
	}
	if (equip[2].name == "HolyGrail") {
		healDice = 2;
	}
}

void Entity::takeOff(int type) {
	if (equip[type].name == "MagicWand" || equip[type].name == "RitualSword") {
		att = Skill::hand;
	}
	if (equip[type].name == "LaurelWreath") {
		mDefense /= 1.1;
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
