#pragma once

#include <stdlib.h>
#include <vector>
#include <string>
#include "stat.h"
#include <cmath>
#include "money.h"
#include <time.h>

class Dice {
public:
	Dice();
	std::vector<char> result;
	double max_movement_points;
	double movement_points = 0.0;
	double success_percent;
	void action(Stat& status, int used_focus);
	void attack(Stat& status, int used_focus, int num_of_dice, double success);
};