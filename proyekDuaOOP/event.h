#pragma once
#include<iostream>
#include<stdlib.h>
#include<time.h>

class Event {
public:
	Event();
	Stat stat;
	Money mon;
	int random_event;
	void Random_Event();
};