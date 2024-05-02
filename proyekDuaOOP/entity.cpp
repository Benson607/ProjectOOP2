#include "entity.h"

Entity::Entity(int type): Stat() {
	rect = Rect(type);
}
