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

#include <conio.h>

using namespace std;
using namespace Draw;

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

void fight(vector<Role*>& roles, vector<Enemy*>& enemys) {
	system("CLS");
	vector<Entity*> entitys;
	for (int i = 0; i < roles.size(); i++) {
		roles[i]->setPosDraw(110 + i * 15, 32);
		entitys.push_back(roles[i]);
	}
	for (int i = 0; i < enemys.size(); i++) {
		enemys[i]->setPosDraw(i * 15, 0);
		entitys.push_back(enemys[i]);
	}
	for (int i = 0; i < entitys.size(); i++) {
		entitys[i]->actionTimes = -1;
		entitys[i]->addActionTimes();
	}
	int input = -1;
	system("CLS");
	while (1) {
		if (input == 27) {
			break;
		}
		for (int i = 0; i < entitys.size(); i++) {
			int min = i;
			for (int j = i + 1; j < entitys.size(); j++) {
				if (entitys[j]->cmp(*entitys[min])) {
					min = j;
				}
			}
			Entity* temp = entitys[i];
			entitys[i] = entitys[min];
			entitys[min] = temp;
		}
		for (int i = 0; i < entitys.size(); i++) {
			entitys[i]->inAction = 0;
		}
		entitys[0]->inAction = 1;
		for (int i = 0; i < roles.size(); i++) {
			if (roles[i]->inAction) {
				setColor(207);
			}
			draw(roles[i]->output(), roles[i]->xDraw, roles[i]->yDraw);
			setColor();
		}
		for (int i = 0; i < enemys.size(); i++) {
			if (enemys[i]->inAction) {
				setColor(207);
			}
			draw(enemys[i]->output(), enemys[i]->xDraw, enemys[i]->yDraw);
			setColor();
		}
		vector<string> space = {
			"               ",
			"               ",
			"               ",
			"               ",
			"               ",
			"               "
		};
		draw(space, 0, 32);
		for (int i = 0; i < 6; i++) {
			gotoxy(0, 32 + i);
			cout << entitys[i]->name;
		}
		entitys[0]->addActionTimes();
		input = _getch();
	}
}

int main() {
	inRange();
	draw(pic, 0, 0);
	Role player1(1, "chen-yon-fa");
	Role player2(2, "Alus");
	Role player3(3, "boring bowling");
	Enemy enemy1("tai-wen-kai");
	Enemy enemy2("ju-ciau");
	Enemy enemy3("shui-cin-chun");
	vector<Role*> roles = { &player1, &player2, &player3 };
	vector<Enemy*> enemys = { &enemy1, &enemy2, &enemy3 };
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
	fight(roles, enemys);
}