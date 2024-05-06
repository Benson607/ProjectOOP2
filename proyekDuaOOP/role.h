#pragma once

#include "entity.h"
#include "item.h"

class Role :public Entity {
public:
	Role(int num, std::string name = "");
	Item item;
};