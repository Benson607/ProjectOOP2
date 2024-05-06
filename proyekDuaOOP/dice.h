#pragma once

#include <stdlib.h>
#include<vector>

class Dice {
public:
	Dice();
	std::vector<int> result;
	Stat stat;
	void action();
	void attack();
};