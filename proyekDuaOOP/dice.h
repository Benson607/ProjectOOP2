#pragma once

#include <vector>
#include <cmath>

#include "stat.h"
#include "money.h"

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