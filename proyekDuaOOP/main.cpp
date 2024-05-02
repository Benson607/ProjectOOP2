#include "role.h"
#include "enemy.h"
#include "map.h"

int main() {
	Role player1(1);
	Role player2(2);
	Role player3(3);
	Map map;
	map.setRect(player1.rect);
	map.setWall();
	map.show();
}