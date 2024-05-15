#pragma once

#include <stdlib.h>
#include <vector>
#include<time.h>

#include "stat.h"

class Dice {
public:
	Dice();
	std::vector<int> result;
	Stat stat;
	void action();
	void attack();
};