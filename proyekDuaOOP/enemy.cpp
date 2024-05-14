#include "enemy.h"

Enemy::Enemy(std::string name) :Entity(4, name) {
	focus = 0;
}

Enemy::~Enemy() {
	Entity::~Entity();
}
