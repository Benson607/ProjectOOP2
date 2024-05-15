#include <conio.h>

#include "draw.h"
#include "enemy.h"
#include "map.h"
#include "role.h"
#include "dice.h"

using namespace Draw;

std::vector<std::string> pic = {
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
  "                                                                                                                                                           " };

void fight(std::vector<Entity*>& roles, std::vector<Entity*>& enemys) {
	system("CLS");
	std::vector<Entity*> entitys;
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
	std::vector<std::string> space = {
			"               ",
			"               ",
			"               ",
			"               ",
			"               ",
			"               " };
	bool flee = 0;
	while (!flee) {
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
		draw(space, 0, 32);
		for (int i = 0; i < 6; i++) {
			gotoxy(0, 32 + i);
			std::cout << entitys[i]->name;
		}
		flee = entitys[0]->actionForFight(roles, enemys);
		entitys[0]->addActionTimes();
	}
}

int main() {
	inRange();
	draw(pic, 0, 0);
	Role player1(1, "chen-yon-fa");
	Role           player2(2, "Alus");
	Role           player3(3, "boring bowling");
	Enemy          enemy1("tai-wen-kai");
	Enemy          enemy2("ju-ciau");
	Enemy          enemy3("shui-cin-chun");
	std::vector<Entity*>  roles = { &player1, &player2, &player3 };
	std::vector<Entity*> enemys = { &enemy1, &enemy2, &enemy3 };
	int            input = -1;
	input = _getch();
	system("CLS");
	std::string playerName = "";
	std::cout << "Please enter your name:" << std::endl;
	do {
		std::cin >> playerName;
		system("CLS");
		if (playerName == "Tai-Wen-Kai") {
			std::cout << "Tai-Wen-Kai already be signed. Suggest you use xXTai-Wen-KaiXx or Tai-Wen-Kai123" << std::endl;
		}
	} while (playerName == "Tai-Wen-Kai");
	system("CLS");

	Map map;
	map.setWall();  //Wall
	map.setRect(player1.rect);   //Player1
	map.setRect(player2.rect);   //Player2
	map.setRect(player3.rect);   //Palyer3
	map.setRect(enemy1.rect);   //Enemy1
	map.setRect(enemy2.rect);   //Enemy2
	map.setRect(enemy3.rect);
	map.show();

	// decide the orders
	int turn[3] = { 0 };
	if (player1.cmp(player2) || player1.cmp(player3)) {
		turn[0] = player1.speed;
		if (player2.cmp(player3)) {
			turn[1] = player2.speed;
			turn[2] = player3.speed;   // 1-2-3
		}
		else {
			turn[1] = player3.speed;
			turn[2] = player2.speed;   //1-3-2
		}
	}
	else if (player2.cmp(player1) || player2.cmp(player3)) {
		turn[0] = player2.speed;
		if (player1.cmp(player3)) {
			turn[1] = player1.speed;
			turn[2] = player3.speed;   //2-1-3
		}
		else {
			turn[1] = player3.speed;
			turn[2] = player1.speed;   //2-3-1
		}
	}
	else if (player3.cmp(player1) || player3.cmp(player2)) {
		turn[0] = player3.speed;
		if (player1.cmp(player2)) {
			turn[1] = player1.speed;
			turn[2] = player2.speed;   //3-1-2
		}
		else {
			turn[1] = player2.speed;
			turn[2] = player1.speed;   //3-2-1
		}
	}

	// operate
	int move_time = 0;
	Dice dice;
	while (1) {  //while enemy still exist,loop
		for (int i = 0; i < 3; i++) {
			if (turn[i] == player1.speed) {  //player1 move
				dice.action(player1);
				move_time = dice.movement_points;
				gotoxy(0, 51);
				setColor(7);
				std::cout << "Player1 move time :" << move_time << std::endl;
				for (int j = move_time; j > 0; j--) { //how many step player1 can move
					map.nowx = player1.rect.x;
					map.nowy = player1.rect.y;

					map.getinput(1);
					gotoxy(player1.rect.y, player1.rect.x);
					setColor(224);
					std::cout << ".";
					gotoxy(map.nowy, map.nowx);
					setColor(230);
					std::cout << "1";

					player1.rect.x = map.nowx;
					player1.rect.y = map.nowy;
					while ((player1.rect.x == enemy1.rect.x && player1.rect.y == enemy1.rect.y) || (player1.rect.x == enemy2.rect.x && player1.rect.y == enemy2.rect.y) || (player1.rect.x == enemy3.rect.x && player1.rect.y == enemy3.rect.y)) {
						system("CLS");
						setColor(7);
						fight(roles, enemys);
					}

				}
			}
			else if (turn[i] == player2.speed) {  //player2 move
				dice.action(player2);
				move_time = dice.movement_points;
				gotoxy(0, 51);
				setColor(7);
				std::cout << "Player2 move time :" << move_time << std::endl;
				for (int j = move_time; j > 0; j--) { //how many step player1 can move
					map.nowx = player2.rect.x;
					map.nowy = player2.rect.y;

					map.getinput(2);
					gotoxy(player2.rect.y, player2.rect.x);
					setColor(224);
					std::cout << ".";
					gotoxy(map.nowy, map.nowx);
					setColor(230);
					std::cout << "2";

					player2.rect.x = map.nowx;
					player2.rect.y = map.nowy;
					while ((player2.rect.x == enemy1.rect.x && player2.rect.y == enemy1.rect.y) || (player2.rect.x == enemy2.rect.x && player2.rect.y == enemy2.rect.y) || (player2.rect.x == enemy3.rect.x && player2.rect.y == enemy3.rect.y)) {
						system("CLS");
						setColor(7);
						fight(roles, enemys);
					}

				}
			}
			else if (turn[i] == player3.speed) {  //player 3 move
				dice.action(player3);
				move_time = dice.movement_points;
				gotoxy(0, 51);
				setColor(7);
				std::cout << "Player3 move time :" << move_time << std::endl;
				for (int j = move_time; j > 0; j--) { //how many step player1 can move
					map.nowx = player3.rect.x;
					map.nowy = player3.rect.y;

					map.getinput(3);
					gotoxy(player3.rect.y, player3.rect.x);
					setColor(224);
					std::cout << ".";
					gotoxy(map.nowy, map.nowx);
					setColor(230);
					std::cout << "3";

					player3.rect.x = map.nowx;
					player3.rect.y = map.nowy;
					while ((player3.rect.x == enemy1.rect.x && player3.rect.y == enemy1.rect.y) || (player3.rect.x == enemy2.rect.x && player3.rect.y == enemy2.rect.y) || (player3.rect.x == enemy3.rect.x && player3.rect.y == enemy3.rect.y)) {
						system("CLS");
						setColor(7);
						fight(roles, enemys);
					}

				}
			}
		}
	}


	fight(roles, enemys);
	
	return 0;
}
