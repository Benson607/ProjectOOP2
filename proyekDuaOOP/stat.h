#pragma once

#include <time.h>
#include <stdlib.h>

class Stat {
public:
	double vitality_max;
	double focus_max;

	double vitality;
	double focus;
	double speed;
	double hitrate;
	double pAttack;
	double mAttack;
	double pDefense;
	double mDefense;

	Stat(bool i = 1);
	void operator=(Stat value);
	double& operator[](int i);
	double& getMax(int i);
	void operator+=(Stat value);
	void operator-=(Stat value);
};