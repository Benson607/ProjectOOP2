#pragma once

#include "stat.h"
#include "rect.h"

class Entity :public Stat {
public:
	Rect rect;
	Entity(int type);
};