#include "role.h"

Role::Role(int num, std::string name): Entity(num, name) {
}

Role::~Role() {
	Entity::~Entity();
}
