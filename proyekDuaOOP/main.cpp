#include "role.h"
#include "enemy.h"
#include "map.h"
#include "draw.h"

#include <conio.h>

using namespace std;

void fight() {
	system("CLS");
	Role player1(1, "chen-yon-fa");
	Role player2(2, "Alus");
	Role player3(3, "fainay");
	Enemy enemy1("tai-wen-kai");
	Enemy enemy2("ju-ciau");
	vector<Role> roles = { player1, player2, player3 };
	vector<Enemy> enemys = { enemy1,enemy2 };
	int input = -1;
	system("CLS");
	while (1) {
		if (input == 27) {
			break;
		}
		for (int i = 0; i < enemys.size(); i++) {
			Draw().draw(enemys[i].output(), 15 * i, 0);
		}
		input = _getch();
	}
}

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
	Draw().inRange();
	fight();
}