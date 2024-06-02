#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "money.h"
#include "stat.h"

class Event {
public:
	Event();
	Stat stat;
	int random_event;
	void Random_Event(Stat& status);
};