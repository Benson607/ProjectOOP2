#include "stat.h"

Stat::Stat() {
	vitality_max = rand()%15 + 30;
	focus_max = 3;
	speed_max = rand()%25 + 30;

	hitrate_max = rand() % 20 + 40;
	pAttack_max = rand() % 11 + 5;
	mAttack_max = rand() % 11 + 5;
	pDefense_max = rand() % 21;
	mDefense_max = rand() % 21;

	vitality = vitality_max;
	focus = focus_max;
	speed = speed_max;
	hitrate = hitrate_max;
	pAttack = pAttack_max;
	mAttack = mAttack_max;
	pDefense = pDefense_max;
	mDefense = mDefense_max;
}

void Stat::operator=(Stat value) {
	for (int i = 0; i < 8; i++) {
		this[0][i] = value[i];
	}
}

double& Stat::operator[](int i)
{
	switch (i)
	{
	case 0:
		return vitality;
		break;
	case 1:
		return focus;
		break;
	case 2:
		return speed;
		break;
	case 3:
		return hitrate;
		break;
	case 4:
		return pAttack;
		break;
	case 5:
		return mAttack;
		break;
	case 6:
		return pDefense;
		break;
	case 7:
		return mDefense;
		break;
	default:
		break;
	}
}

void Stat::operator+=(Stat value) {
	for (int i = 0; i < 8; i++) {
		this[0][i] += value[i];
	}
}