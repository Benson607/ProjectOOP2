#include "stat.h"

Stat::Stat() {
	vitality = rand()%15 + 30;
	focus = 3;
	speed = rand()%25 + 30;
	accuracy = rand() % 20 + 40;
	pAttack = rand() % 11 + 5;
	mAttack = rand() % 11 + 5;
	pDefense = rand() % 21;
	mDefense = rand() % 21;
}
