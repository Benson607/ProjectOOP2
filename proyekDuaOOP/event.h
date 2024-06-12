#pragma once

#include <iostream>
#include <vector>
#include <conio.h>

#include "stat.h"
#include "money.h"
#include "draw.h"

class Event {
public:
	Event();
	Stat stat;
	int random_event;
	void Random_Event(Stat& status);
	std::vector<std::string> statment;
};