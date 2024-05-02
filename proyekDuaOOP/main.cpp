#include "role.h"
#include "enemy.h"
#include "map.h"

int main() {
	Role player1(1);
	Role player2(2);
	Role player3(3);
	Enemy enemy;
	Map map;
	map.setRect(player1.rect);
	map.setRect(player2.rect);
	map.setRect(player3.rect);
	map.setRect(enemy.rect);
	map.setWall();
	map.show();
}