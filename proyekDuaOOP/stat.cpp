#include "stat.h"

Stat::Stat(bool i) {
	if (i) {
		vitality_max = rand() % 15 + 30;
		focus_max = 3;

		vitality = vitality_max;
		focus = 3;
		speed = rand() % 25 + 30;
		hitrate = rand() % 20 + 40;
		pAttack = rand() % 11 + 5;
		mAttack = rand() % 11 + 5;
		pDefense = rand() % 21;
		mDefense = rand() % 21;
	}
	else {
		vitality_max = 0;
		focus_max = 0;

		vitality = 0;
		focus = 0;
		speed = 0;
		hitrate = 0;
		pAttack = 0;
		mAttack = 0;
		pDefense = 0;
		mDefense = 0;
	}
}

void Stat::operator=(Stat value) {
	for (int i = 0; i < 8; i++) {
		this[0][i] = value[i];
	}
}

double& Stat::operator[](int i) {
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

double& Stat::getMax(int i) {
	switch (i)
	{
	case 0:
		return vitality_max;
		break;
	case 1:
		return focus_max;
		break;
	default:
		break;
	}
}

void Stat::operator+=(Stat value) {
	for (int i = 0; i < 2; i++) {
		getMax(i) += value.getMax(i);
	}
	for (int i = 0; i < 8; i++) {
		this[0][i] += value[i];
	}
}

void Stat::operator-=(Stat value) {
	for (int i = 0; i < 2; i++) {
		getMax(i) -= value.getMax(i);
	}
	for (int i = 0; i < 8; i++) {
		this[0][i] -= value[i];
	}
}
