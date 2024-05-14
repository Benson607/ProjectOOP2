#pragma once

#include <stdlib.h>
#include <vector>
#include <string>
#include "stat.h"
#include "role.h"
#include <cmath>
#include "money.h"
#include <time.h>

class Dice {
public:
	Dice();
	std::vector<int> result;
	Stat stat;
	Money dollar;
	double max_movement_points;
	double movement_points;
	double success_percent;
	void action(Stat& status);
	void attack(Stat& status);
};