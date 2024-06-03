#pragma once

#include <iostream>

#include "stat.h"
#include "money.h"

class Event {
public:
	Event();
	Stat stat;
	int random_event;
	void Random_Event(Stat& status);
};