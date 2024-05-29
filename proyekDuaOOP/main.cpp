#include <conio.h>

#include "draw.h"
#include "enemy.h"
#include "map.h"
#include "role.h"
#include "dice.h"
#include "shop.h"

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

std::vector<std::string> map_ui = {
  "||--------------------------------------------------------------------------------|",
  "||--------------------------------------------------|-----------------------------|",
  "||                                                  |Turn :                       |",
  "||                                                  |Player Name :                |",
  "||                                                  |Action Points :              |",
  "||                                                  |                             |",
  "||                                                  |                             |",
  "||                                                  |                             |",
  "||                                                  |                             |",
  "||                                                  |                             |",
  "||                                                  |                             |",
  "||                                                  |                             |",
  "||                                                  |                             |",
  "||                                                  |                             |",
  "||                                                  |                             |",
  "||                                                  |                             |",
  "||                                                  |                             |",
  "||                                                  |                             |",
  "||                                                  |                             |",
  "||                                                  |                             |",
  "||                                                  |                             |",
  "||                                                  |                             |",
  "||                                                  |                             |",
  "||                                                  |___________Helper____________|",
  "||                                                  |Arrow Key : Move             |",
  "||                                                  |'P' Key : End Turn           |",
  "||                                                  |'I' Key  : Open Bag,         |",
  "||                                                  |   : Wall, . : Road, $ : Shop|",
  "||----|--------------------|---|--------------------|---|--------------------|----|",
  "|     |                    |   |                    |   |                    |    |",
  "|     |                    |   |                    |   |                    |    |",
  "|     |                    |   |                    |   |                    |    |",
  "|     |                    |   |                    |   |                    |    |",
  "|     |                    |   |                    |   |                    |    |",
  "|     |                    |   |                    |   |                    |    |",
  "|     |                    |   |                    |   |                    |    |",
  "|     |                    |   |                    |   |                    |    |",
  "|     |                    |   |                    |   |                    |    |",
  "|-----|--------------------|---|--------------------|---|--------------------|----|" };

std::vector<std::string> choice_player = {
"|--------------------|",
"|                    |",
"|                    |",
"|                    |",
"|                    |",
"|                    |",
"|                    |",
"|                    |",
"|                    |",
"|                    |",
"|--------------------|" };

void show_map_ui() {
	draw(map_ui, 0, 0);
	gotoxy(54, 27);
	setColor(136);
	std::cout << " ";
	gotoxy(64, 27);
	setColor(224);
	std::cout << ".";
	gotoxy(74, 27);
	setColor(240);
	std::cout << "$";
	setColor();
}

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

void Draw_Player_information(std::vector<Entity*>& roles);
void GameLoop(std::vector<Entity*>& roles, std::vector<Entity*>& enemys, Map& map);
void Decide_Turn(std::vector<Entity*>& roles);
void select_players(std::vector<Entity*>& roles,int i);

int main() {
	inRange();
	draw(pic, 0, 0);
	Role player1(1, "chen-yon-fa");
	Role player2(2, "Alus");
	Role player3(3, "boring bowling");
	Enemy enemy1("tai-wen-kai");
	Enemy enemy2("ju-ciau");
	Enemy enemy3("shui-cin-chun");
	std::vector<Entity*> roles = { &player1, &player2, &player3 };
	std::vector<Entity*> enemys = { &enemy1, &enemy2, &enemy3 };
	int input = -1;
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
	map.setShop();
	map.setEvent();
	map.setRect(player1.rect);   //Player1
	map.setRect(player2.rect);   //Player2
	map.setRect(player3.rect);   //Palyer3
	map.setRect(enemy1.rect);    //Enemy1
	map.setRect(enemy2.rect);    //Enemy2
	map.setRect(enemy3.rect);
	
	Decide_Turn(roles);
	GameLoop(roles, enemys, map);
	return 0;
}

void Draw_Player_information(std::vector<Entity*>& roles) {
	std::vector<Entity*> Entity_map;
	roles[0]->setPosDraw(7 , 29);
	Entity_map.push_back(roles[0]);
	roles[1]->setPosDraw(7 + 26 * 1, 29);
	Entity_map.push_back(roles[1]);
	roles[2]->setPosDraw(7 + 26 * 2, 29);
	Entity_map.push_back(roles[2]);
	setColor();
	for (int i = 0; i < roles.size(); i++) {
		if (roles[i]->inAction) {
			setColor(207);
		}
		draw(roles[i]->output(), roles[i]->xDraw, roles[i]->yDraw);
		setColor();
	}
}

void select_players(std::vector<Entity*>& roles,int i) {
	if (roles[i]->name == "chen-yon-fa") {
		setColor(10);
		draw(choice_player, 6, 28);
		setColor();
		draw(choice_player, 31, 28);
		draw(choice_player, 56, 28);
	}
	else if (roles[i]->name == "Alus") {
		setColor();
		draw(choice_player, 6, 28);
		setColor(10);
		draw(choice_player, 31, 28);
		setColor();
		draw(choice_player, 56, 28);
	}
	else if (roles[i]->name == "boring bowling") {
		setColor();
		draw(choice_player, 6, 28);
		draw(choice_player, 31, 28);
		setColor(10);
		draw(choice_player, 56, 28);
	}
}

void Decide_Turn(std::vector<Entity*>& roles) {
	// decide the orders
	std::vector<Entity*> stay;
	for (int i = 0; i < roles.size(); i++) {
		stay.push_back(roles[i]);
	}

	int turn[3] = { 0 };
	if (roles[0]->cmp(*roles[1]) && roles[0]->cmp(*roles[2])) {
		turn[0] = 0;
		if (roles[1]->cmp(*roles[2])) {
			turn[1] = 1;
			turn[2] = 2;   // 1-2-3
		}
		else {
			turn[1] = 2;
			turn[2] = 1;   //1-3-2
		}
	}
	else if (roles[1]->cmp(*roles[0]) && roles[1]->cmp(*roles[2])) {
		turn[0] = 1;
		if (roles[0]->cmp(*roles[2])) {
			turn[1] = 0;
			turn[2] = 2;   //2-1-3
		}
		else {
			turn[1] = 2;
			turn[2] = 0;   //2-3-1
		}
	}
	else if (roles[2]->cmp(*roles[0]) && roles[2]->cmp(*roles[1])) {
		turn[0] = 2;
		if (roles[0]->cmp(*roles[1])) {
			turn[1] = 0;
			turn[2] = 1;   //3-1-2
		}
		else {
			turn[1] = 1;
			turn[2] = 0;   //3-2-1
		}
	}

	roles.clear();
	for (int i = 0; i < 3; i++) {
		if (turn[0] == 0) {
			roles.push_back(stay[0]);
			if (turn[1] == 1) {
				roles.push_back(stay[1]);
				roles.push_back(stay[2]);
			}
			else {
				roles.push_back(stay[2]);
				roles.push_back(stay[1]);
			}
		}
		else if (turn[0] == 1) {
			roles.push_back(stay[1]);
			if (turn[1] == 0) {
				roles.push_back(stay[0]);
				roles.push_back(stay[2]);
			}
			else {
				roles.push_back(stay[2]);
				roles.push_back(stay[0]);
			}
		}
		else if (turn[0] == 2) {
			roles.push_back(stay[2]);
			if (turn[1] == 0) {
				roles.push_back(stay[0]);
				roles.push_back(stay[1]);
			}
			else {
				roles.push_back(stay[1]);
				roles.push_back(stay[0]);
			}
		}
	}
}

void GameLoop(std::vector<Entity*>& roles, std::vector<Entity*>& enemys, Map& map) {
	// operate
	int wheather_use_focus = 0;
	int Turn_Counted = 1;
	Dice dice;
	show_map_ui();
	Draw_Player_information(roles);
	while (1) {  //while enemy still exist,loop
		gotoxy(59, 2);
		setColor();
		std::cout << Turn_Counted;
		for (int i = 0; i < 3; i++) {
			Draw::drawMap(map, roles[i]->rect.x - 12, roles[i]->rect.y - 25);
			gotoxy(66, 3);
			std::cout << "               ";
			gotoxy(66, 3);
			std::cout << roles[i]->name;
			gotoxy(68, 4);
			std::cout << "          ";

			select_players(roles,i);
			Draw_Player_information(roles);
			setColor();
			gotoxy(0, 40);
			std::cout << "Do you wnat to use focus?" << std::endl;
			std::cin >> wheather_use_focus;
			dice.action(*roles[i], wheather_use_focus);

			gotoxy(68, 4);
			for (int k = 0; k < dice.result.size(); k++) {
				if (dice.result[k] == 'T') {
					setColor(14);
					std::cout << "T";
				}
				else if (dice.result[k] == 'F') {
					setColor(8);
					std::cout << "F";
				}
			}

			for (int j = dice.movement_points; j > 0; j--) { //how many step player1 can move
				setColor();
				Draw_Player_information(roles);
				
				gotoxy(0, 40);
				setColor();
				std::cout << "Do you wnat to use focus?" << std::endl << wheather_use_focus;

				map.nowx = roles[i]->rect.x;
				map.nowy = roles[i]->rect.y;
				if (roles[i]->name == "chen-yon-fa") 
					map.getinput(1, roles[0]->rect.x, roles[0]->rect.y, roles[1]->rect.x, roles[1]->rect.y, roles[2]->rect.x, roles[2]->rect.y);
				
				else if (roles[i]->name == "Alus") 
					map.getinput(2, roles[0]->rect.x, roles[0]->rect.y, roles[1]->rect.x, roles[1]->rect.y, roles[2]->rect.x, roles[2]->rect.y);
					
				else if (roles[i]->name == "boring bowling") 
					map.getinput(3, roles[0]->rect.x, roles[0]->rect.y, roles[1]->rect.x, roles[1]->rect.y, roles[2]->rect.x, roles[2]->rect.y);
				
				//if getinput new position meet enemy, fight
				if ((map.nowx == enemys[0]->rect.x && map.nowy == enemys[0]->rect.y) || (map.nowx == enemys[1]->rect.x && map.nowy == enemys[1]->rect.y) || (map.nowx == enemys[2]->rect.x && map.nowy == enemys[2]->rect.y)) {
					system("CLS");
					setColor(7);
					fight(roles, enemys);
					system("CLS");
					map.set_new_rect_type(map.nowx, map.nowy, 'E');
					show_map_ui();
					gotoxy(59, 2);
					setColor();
					std::cout << Turn_Counted;
					gotoxy(66, 3);
					std::cout << "               ";
					gotoxy(66, 3);
					std::cout <<roles[i]->name;
					gotoxy(68, 4);
					std::cout << "          ";

					Draw_Player_information(roles);

					select_players(roles, i);

					roles[i]->rect.x = map.nowx;
					roles[i]->rect.y = map.nowy;
					Draw::drawMap(map, roles[i]->rect.x - 12, roles[i]->rect.y - 25);
					/*if () {
						player1.rect.x = map.nowx;
						player1.rect.y = map.nowy;
						map.set_new_rect_type(1);  //set player on enemy's original position
						Draw::drawMap(map, player1.rect.x - 12, player1.rect.y - 25);

					}
					else {
						Draw::drawMap(map, player1.rect.x - 12, player1.rect.y - 25);
					}*/

				}
				else {
					/*show_map_ui();
					gotoxy(59, 2);
					setColor();
					std::cout << Turn_Counted;
					gotoxy(66, 3);
					std::cout << "               ";
					gotoxy(66, 3);
					std::cout << roles[i]->name;
					gotoxy(68, 4);
					std::cout << "          ";

					Draw_Player_information(roles);*/

					
					roles[i]->rect.x = map.nowx;
					roles[i]->rect.y = map.nowy;
					Draw::drawMap(map, roles[i]->rect.x - 12, roles[i]->rect.y - 25);
				}
			}
			Turn_Counted++;
		}
	}
}