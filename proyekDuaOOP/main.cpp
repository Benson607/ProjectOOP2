#include "role.h"
#include "enemy.h"
#include "map.h"
#include "draw.h"

#include <conio.h>

using namespace std;

vector<string> pic = {
	"                                                                                                                                                           ",
	"                    forthekingfortheking              forthekingforthekingfortheking              forthekingforthekingfortheking                           ",
	"                    forthekingfortheking              forthekingforthekingfortheking              forthekingforthekingfortheking                           ",
	"                    forthekingfortheking              fortheking          fortheking              fortheking          fortheking                           ",
	"                    fortheking                        fortheking          fortheking              fortheking          fortheking                           ",
	"                    fortheking                        fortheking          fortheking              forthekingforthekingfortheking                           ",
	"                    fortheking                        fortheking          fortheking              forthekingforthekingfortheking                           ",
	"                    forthekingfortheking              fortheking          fortheking              fortheking    fortheking                                 ",
	"                    forthekingfortheking              fortheking          fortheking              fortheking     fortheking                                ",
	"                    fortheking                        fortheking          fortheking              fortheking      fortheking                               ",
	"                    fortheking                        fortheking          fortheking              fortheking       fortheking                              ",
	"                    fortheking                        fortheking          fortheking              fortheking        fortheking                             ",
	"                    fortheking                        fortheking          fortheking              fortheking         fortheking                            ",
	"                    fortheking                        forthekingforthekingfortheking              fortheking          fortheking                           ",
	"                    fortheking                        forthekingforthekingfortheking              fortheking           fortheking                          ",
	"                                                                                                                                                           ",
	"                                                     TTTTTTTT   HH     HH   EEEEEEEE                                                                       ",
	"                                                        TT      HH     HH   EE                                                                             ",
	"                                                        TT      HHHHHHHHH   EEEEEEEE                                                                       ",
	"                                                        TT      HH     HH   EE                                                                             ",
	"                                                        TT      HH     HH   EEEEEEEE                                                                       ",
	"                                                                                                                                                           ",
	"            fortheking        fortheking  fortheking  forthekingfortheking                fortheking                fortheking                             ",
	"            fortheking       fortheking   fortheking  fortheking fortheking               fortheking          fortheking   fortheking                      ",
	"            fortheking      fortheking    fortheking  fortheking  fortheking              fortheking        fortheking       fortheking                    ",
	"            fortheking     fortheking     fortheking  fortheking   fortheking             fortheking      fortheking           fortheking                  ",
	"            fortheking    fortheking      fortheking  fortheking    fortheking            fortheking    fortheking              fortheking                 ",
	"            fortheking   fortheking       fortheking  fortheking     fortheking           fortheking   fortheking                fortheking                ",
	"            fortheking  fortheking        fortheking  fortheking      fortheking          fortheking  fortheking                  fortheking               ",
	"            fortheking fortheking         fortheking  fortheking       fortheking         fortheking  fortheking                                           ",
	"            forthekingfortheking          fortheking  fortheking        fortheking        fortheking  fortheking                                           ",
	"            fortheking fortheking         fortheking  fortheking         fortheking       fortheking  fortheking                                           ",
	"            fortheking  fortheking        fortheking  fortheking          fortheking      fortheking  fortheking        forthekingfortheking               ",
	"            fortheking   fortheking       fortheking  fortheking           fortheking     fortheking   fortheking       forthekingfortheking               ",
	"            fortheking    fortheking      fortheking  fortheking            fortheking    fortheking    fortheking              fortheking                 ",
	"            fortheking     fortheking     fortheking  fortheking             fortheking   fortheking      fortheking           fortheking                  ",
	"            fortheking      fortheking    fortheking  fortheking              fortheking  fortheking        fortheking       fortheking                    ",
	"            fortheking       fortheking   fortheking  fortheking               fortheking fortheking          fortheking   fortheking                      ",
	"            fortheking        fortheking  fortheking  fortheking                forthekingfortheking                fortheking                             ",
	"                                                                                                                                                           "
};

void fight() {
	system("CLS");
	Role player1(1, "chen-yon-fa");
	Role player2(2, "Alus");
	Role player3(3, "boring bowling");
	player1.setPosDraw(110, 32);
	player2.setPosDraw(125, 32);
	player3.setPosDraw(140, 32);
	Enemy enemy1("tai-wen-kai");
	Enemy enemy2("ju-ciau");
	Enemy enemy3("shui-cin-chun");
	enemy1.setPosDraw(0, 0);
	enemy2.setPosDraw(15, 0);
	enemy3.setPosDraw(30, 0);
	vector<Role> roles = { player1, player2, player3 };
	vector<Enemy> enemys = { enemy1, enemy2, enemy3 };
	vector<Entity*> entitys;
	entitys.push_back(&player1);
	entitys.push_back(&player2);
	entitys.push_back(&player3);
	entitys.push_back(&enemy1);
	entitys.push_back(&enemy2);
	entitys.push_back(&enemy3);
	for (int i = 0; i < 6; i++) {
		entitys[i]->actionTimes = -1;
		entitys[i]->addActionTimes();
	}
	int input = -1;
	system("CLS");
	while (1) {
		if (input == 27) {
			break;
		}
		for (int i = 0; i < 6; i++) {
			int min = i;
			for (int j = i + 1; j < 6; j++) {
				if (entitys[j]->priority < entitys[min]->priority) {
					min = j;
				}
				else if (entitys[j]->priority == entitys[min]->priority) {
					if (entitys[j]->speed > entitys[min]->speed) {
						min = j;
					}
					else if (entitys[j]->speed < entitys[min]->speed) {
						continue;
					}
					else if (entitys[j]->pAttack + entitys[j]->mAttack > entitys[min]->pAttack + entitys[min]->mAttack) {
						min = j;
					}
					else if (entitys[j]->pAttack + entitys[j]->mAttack < entitys[min]->pAttack + entitys[min]->mAttack) {
						continue;
					}
					else if (entitys[j]->pDefense + entitys[j]->mDefense > entitys[min]->pDefense + entitys[min]->mDefense) {
						min = j;
					}
					else if (entitys[j]->pDefense + entitys[j]->mDefense < entitys[min]->pDefense + entitys[min]->mDefense) {
						continue;
					}
					else if (entitys[j]->vitality > entitys[min]->vitality) {
						min = j;
					}
					else if (entitys[j]->vitality < entitys[min]->vitality) {
						continue;
					}
				}
			}
			Entity* temp = entitys[i];
			entitys[i] = entitys[min];
			entitys[min] = temp;
		}
		Draw().draw(player1.output(), player1.xDraw, player1.yDraw);
		Draw().draw(player2.output(), player2.xDraw, player2.yDraw);
		Draw().draw(player3.output(), player3.xDraw, player3.yDraw);
		Draw().draw(enemy1.output(), enemy1.xDraw, enemy1.yDraw);
		Draw().draw(enemy2.output(), enemy2.xDraw, enemy2.yDraw);
		Draw().draw(enemy3.output(), enemy3.xDraw, enemy3.yDraw);
		vector<string> space = {
			"               ",
			"               ",
			"               ",
			"               ",
			"               ",
			"               "
		};
		Draw().draw(space, 0, 32);
		for (int i = 0; i < 6; i++) {
			Draw().gotoxy(0, 32 + i);
			cout << entitys[i]->name;
		}
		entitys[0]->addActionTimes();
		input = _getch();
	}
}

int main() {
	Draw().inRange();
	Draw().draw(pic, 0, 0);
	int input = -1;
	input = _getch();
	system("CLS");
	string playerName = "";
	cout << "Please enter your name:" << endl;
	do {
		cin >> playerName;
		system("CLS");
		if (playerName == "Tai-Wen-Kai") {
			cout << "Tai-Wen-Kai already be signed. Suggest you use xXTai-Wen-KaiXx or Tai-Wen-Kai123" << endl;
		}
	} while (playerName == "Tai-Wen-Kai");
	system("CLS");
	Map map;
	map.setWall();
	fight();
}