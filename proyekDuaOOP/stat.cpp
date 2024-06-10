#include "stat.h"

Stat::Stat(bool i) {
	if (i) {
		vitality_max = rand() % 15 + 30;
		focus_max = 3;
		speed_max = rand() % 25 + 30;
		hitrate_max = rand() % 20 + 40;
		pAttack_max = rand() % 11 + 5;
		mAttack_max = rand() % 11 + 5;
		pDefense_max = rand() % 21;
		mDefense_max = rand() % 21;

		vitality = vitality_max;
		focus = 3;
		speed = speed_max;
		hitrate = hitrate_max;
		pAttack = pAttack_max;
		mAttack = mAttack_max;
		pDefense = pDefense_max;
		mDefense = mDefense_max;
	}
	else {
		vitality_max = 0;
		focus_max = 0;
		speed_max = 0;
		hitrate_max = 0;
		pAttack_max = 0;
		mAttack_max = 0;
		pDefense_max = 0;
		mDefense_max = 0;

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
	case 2:
		return speed_max;
		break;
	case 3:
		return hitrate_max;
		break;
	case 4:
		return pAttack_max;
		break;
	case 5:
		return mAttack_max;
		break;
	case 6:
		return pDefense_max;
		break;
	case 7:
		return mDefense_max;
		break;
	default:
		break;
	}
}

void Stat::operator+=(Stat value) {
	for (int i = 0; i < 8; i++) {
		getMax(i) += value.getMax(i);
	}
	for (int i = 0; i < 8; i++) {
		this[0][i] += value[i];
		if (this[0][i] > getMax(i)) {
			this[0][i] = getMax(i);
		}
	}
}

void Stat::operator-=(Stat value) {
	for (int i = 0; i < 8; i++) {
		getMax(i) -= value.getMax(i);
		if (getMax(i) < 0) {
			getMax(i) = 0;
		}
	}
	for (int i = 0; i < 8; i++) {
		this[0][i] -= value[i];
		if (this[0][i] < 0) {
			this[0][i] = 0;
		}
	}
}
