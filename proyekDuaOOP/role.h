#pragma once

#include "entity.h"

class Role :public Entity {
public:
	Role(int num, std::string name = "");
};