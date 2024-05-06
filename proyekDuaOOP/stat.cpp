#include "stat.h"

Stat::Stat() {
	vitality = rand() % 15 + 30;
	focus = 3;
	speed = rand() % 25 + 30;
	accuracy = rand() % 20 + 40;
	pAttack = rand() % 11 + 5;
	mAttack = rand() % 11 + 5;
	pDefense = rand() % 21;
	mDefense = rand() % 21;
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
		return accuracy;
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