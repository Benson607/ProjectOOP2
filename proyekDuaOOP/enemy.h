#pragma once

#include "entity.h"

class Enemy :public Entity {
public:
	Enemy(std::string name = "");
	~Enemy();
};