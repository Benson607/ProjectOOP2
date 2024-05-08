#include "role.h"
#include "enemy.h"
#include "map.h"
#include "draw.h"

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
	std::cout << player1.rect.x << " " << player1.rect.y << std::endl;

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
	map.setObject();
	map.setRect(player1.rect);   //Player1
	map.setRect(player2.rect);   //Player2
	map.setRect(player3.rect);   //Palyer3
	map.setRect(enemy1.rect);   //Enemy1
	map.setRect(enemy2.rect);   //Enemy2
	map.setRect(enemy3.rect);   //Enemy
	map.show();
	
	while (1) {
		map.nowx = player1.rect.x;
		map.nowy = player1.rect.y;
		map.getinput(1);
		player1.rect.x = map.nowx;
		player1.rect.y = map.nowy;
		system("CLS");
		map.show();
	}

	/*double turn[3] = {player1.speed,player2.speed,player3.speed};
	double stay=0;
	for (int i = 0; i < 2; i++) {   //sort playses'speed
		if (turn[i] > turn[i + 1]) {
			turn[i] = stay;
			turn[i] = turn[i + 1];
			turn[i + 1] = stay;
		}
	}*/

	/*while (1) {   //if enemy exist,continue
		for (int i = 0; i < 3; i++) {
			if (turn[i] == player1.speed) {  //player1 move
				//for (int j = 0; j < move_time; j++) {
						//calculus move_time
				//}
				int nowx = player1.rect.x;
				int nowy = player1.rect.y;
				map.getinput(nowx, nowy,1);

				player1.rect.x = nowx;
				player1.rect.y = nowy;
				

			}
			else if (turn[i] == player2.speed) {  //player2 move

			}
			else if (turn[i] == player3.speed) {  //player 3 move
				
			}
		}
	}*/

	//loop game


	//fight(roles, enemys);
}