#pragma once

#include "stat.h"
#include "rect.h"
#include <string>
#include <vector>

class Entity :public Stat {
public:
	Rect rect;
	Entity(int type,std::string name = "");
	std::string name;
	void setName(std::string name);
	std::vector<std::string> output();
};