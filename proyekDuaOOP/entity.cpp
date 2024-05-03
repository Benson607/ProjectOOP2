#include "entity.h"

std::string itos(int x) {
	std::string ans = "";
	while (x) {
		ans.insert(ans.begin(), x % 10 + 48);
		x /= 10;
	}
	return ans;
}

Entity::Entity(int type, std::string name) : Stat(), name(name) {
	rect = Rect(type);
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
		"accuracy:",
		"pAttack:",
		"mAttack:",
		"pDefense:",
		"mDefense:" };
	for (int i = 1; i < 9; i++) {
		out[i] = out[i] + itos(this[0][i - 1]);
	}
	return out;
}

