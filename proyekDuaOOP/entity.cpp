#include "entity.h"

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
	actionTimes = 0;
}

void Entity::setName(std::string name) {
	this->name = name;
}

std::vector<std::string> Entity::output() {
	std::vector<std::string> out = {
		name,
		"vitality:",
		"focus:",
		"speed:",
		"hitRate:",
		"pAttack:",
		"mAttack:",
		"pDefense:",
		"mDefense:" };
	for (int i = 1; i < 9; i++) {
		out[i] = out[i] + itos(this[0][i - 1]);
	}
	return out;
}

void Entity::addActionTimes(){
	actionTimes++;
	priority = (actionTimes + 1) / speed * 100;
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
