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

void pick_inventory()
{
	int input = _getch();
	while (input != 27) {
		//int tmp_x = 2;
		//int tmp_y = 53;
		switch (input)
		{
		case 119://w
			if (Bag::pos_xy.size() == 0) {
				Draw::setColor();
				Bag::statment = { "Empty                        " };
				Draw::draw(Bag::statment, 53, 22);
			}
			else if (Bag::pos_x > 2) {
				Draw::setColor();
				Bag::bagUI = Draw::readSpace(Bag::pos_y, Bag::pos_x, 1, 29);
				Draw::draw(Bag::bagUI, Bag::pos_y, Bag::pos_x);
				Bag::pos_x -= 1;
				Draw::setColor(246);
				Bag::bagUI = Draw::readSpace(Bag::pos_y, Bag::pos_x, 1, 29);
				Draw::draw(Bag::bagUI, Bag::pos_y, Bag::pos_x);
			}
			break;
		case 115://s
			if (Bag::pos_xy.size() == 0) {
				Draw::setColor();
				Bag::statment = { "Empty                        " };
				Draw::draw(Bag::statment, 53, 22);
			}
			else if (Bag::pos_x < 21) {
				Draw::setColor();
				Bag::bagUI = Draw::readSpace(Bag::pos_y, Bag::pos_x, 1, 29);
				Draw::draw(Bag::bagUI, Bag::pos_y, Bag::pos_x);
				Bag::pos_x += 1;
				Draw::setColor(246);
				Bag::bagUI = Draw::readSpace(Bag::pos_y, Bag::pos_x, 1, 29);
				Draw::draw(Bag::bagUI, Bag::pos_y, Bag::pos_x);
			}
			break;
		case 114://r
			if (Bag::pos_xy.size() == 0) {
				Draw::setColor();
				Bag::statment = { "Empty                        " };
				Draw::draw(Bag::statment, 53, 22);
				break;
			}
			else if(Bag::pos_x < Bag::pos_xy.size()+2) {
				Draw::setColor(27);
				Bag::bagUI = Draw::readSpace(Bag::pos_y, Bag::pos_x, 1, 29);
				Draw::draw(Bag::bagUI, Bag::pos_y, Bag::pos_x);
				Draw::setColor();
				Bag::statment = { "Sure to use?                 " };
				Draw::draw(Bag::statment, 53, 22);
			}

			while (input != 121 && input != 110 && Bag::pos_x < Bag::pos_xy.size() + 2) {
				//if amount == 0;
				input = _getch();
				if (input == 121 && Bag::pos_x < Bag::pos_xy.size()+2) {
					Bag::statment = { "Used!                        " };
					Draw::draw(Bag::statment, 53, 22);

					int flag = 0;
					for (int i = 0; i < Bag::pos_xy.size(); i++) {
						if (Bag::pos_x == Bag::pos_xy[i][0] && Bag::pos_y == Bag::pos_xy[i][1] && Bag::pos_xy[i][2] < 13) {
							Bag::buy_in_E[Bag::pos_xy[i][2]].amount--;
							if (Bag::buy_in_E[Bag::pos_xy[i][2]].amount == 0) {
								flag = 1;
							}
							else {
								Draw::setColor(246);
								Bag::bagUI[0] = Bag::buy_in_E[Bag::pos_xy[i][2]].name + " x " + std::to_string((int)(Bag::buy_in_E[Bag::pos_xy[i][2]].amount));
								Draw::draw(Bag::bagUI, Bag::pos_y, Bag::pos_x);
								Bag::bagUI = Draw::readSpace(Bag::pos_y, Bag::pos_x, 1, 29);
								Draw::draw(Bag::bagUI, Bag::pos_y, Bag::pos_x);
							}
							break;
						}
						else if (Bag::pos_x == Bag::pos_xy[i][0] && Bag::pos_y == Bag::pos_xy[i][1] && Bag::pos_xy[i][2] == 13) {
							Bag::buy_in_T[0].amount--;
							if (Bag::buy_in_T[0].amount == 0) {
								flag = 1;
							}
							else {
								Draw::setColor(246);
								Bag::bagUI[0] = Bag::buy_in_T[0].name + " x " + std::to_string((int)(Bag::buy_in_T[0].amount));
								Draw::draw(Bag::bagUI, Bag::pos_y, Bag::pos_x);
								Bag::bagUI = Draw::readSpace(Bag::pos_y, Bag::pos_x, 1, 29);
								Draw::draw(Bag::bagUI, Bag::pos_y, Bag::pos_x);
							}
							break;
						}
						else if (Bag::pos_x == Bag::pos_xy[i][0] && Bag::pos_y == Bag::pos_xy[i][1] && Bag::pos_xy[i][2] == 14) {
							Bag::buy_in_T[1].amount--;
							if (Bag::buy_in_T[1].amount == 0) {
								flag = 1;
							}
							else {
								Draw::setColor(246);
								Bag::bagUI[0] = Bag::buy_in_T[1].name + " x " + std::to_string((int)(Bag::buy_in_T[1].amount));
								Draw::draw(Bag::bagUI, Bag::pos_y, Bag::pos_x);
								Bag::bagUI = Draw::readSpace(Bag::pos_y, Bag::pos_x, 1, 29);
								Draw::draw(Bag::bagUI, Bag::pos_y, Bag::pos_x);
							}
							break;
						}
						else if (Bag::pos_x == Bag::pos_xy[i][0] && Bag::pos_y == Bag::pos_xy[i][1] && Bag::pos_xy[i][2] == 15) {
							Bag::buy_in_T[2].amount--;
							if (Bag::buy_in_T[2].amount == 0) {
								flag = 1;
							}
							else {
								Draw::setColor(246);
								Bag::bagUI[0] = Bag::buy_in_T[2].name + " x " + std::to_string((int)(Bag::buy_in_T[2].amount));
								Draw::draw(Bag::bagUI, Bag::pos_y, Bag::pos_x);
								Bag::bagUI = Draw::readSpace(Bag::pos_y, Bag::pos_x, 1, 29);
								Draw::draw(Bag::bagUI, Bag::pos_y, Bag::pos_x);

							}
							break;
						}
					}

					if (flag) {
						Bag::pos_xy = std::vector<std::vector<int>>(0);
						Draw::setColor();
						Draw::draw(Bag::clear, 53, 2);
						Bag::statment = { "___________Helper____________","Press W,S to select items    ","Press R to select the one you","want to use                  ","Press Y or N to confirm      " };
						Draw::draw(Bag::statment, 53, 23);
						Bag::pos_x = 2;
						Bag::pos_y = 53;

						for (int i = 0; i < 16; i++) {
							if (i < 13) {
								if (Bag::buy_in_E[i].amount > 0) {
									Bag::store[0] = Bag::pos_x;
									Bag::store[1] = Bag::pos_y;
									Bag::store[2] = i;
									Bag::pos_xy.push_back(Bag::store);
									Bag::bagUI[0] = Bag::buy_in_E[i].name + " x " + std::to_string((int)(Bag::buy_in_E[i].amount));
									Draw::draw(Bag::bagUI, Bag::pos_y, Bag::pos_x);
									Bag::pos_x++;
								}
							}
							else {
								if (i == 13) {
									if (Bag::buy_in_T[0].amount > 0) {
										Bag::store[0] = Bag::pos_x;
										Bag::store[1] = Bag::pos_y;
										Bag::store[2] = 13;
										Bag::pos_xy.push_back(Bag::store);
										Bag::bagUI[0] = Bag::buy_in_T[0].name + " x " + std::to_string((int)(Bag::buy_in_T[0].amount));
										Draw::draw(Bag::bagUI, Bag::pos_y, Bag::pos_x);
										Bag::pos_x++;
									}
								}
								if (i == 14) {
									if (Bag::buy_in_T[1].amount > 0) {
										Bag::store[0] = Bag::pos_x;
										Bag::store[1] = Bag::pos_y;
										Bag::store[2] = 14;
										Bag::pos_xy.push_back(Bag::store);
										Bag::bagUI[0] = Bag::buy_in_T[1].name + " x " + std::to_string((int)(Bag::buy_in_T[1].amount));
										Draw::draw(Bag::bagUI, Bag::pos_y, Bag::pos_x);
										Bag::pos_x++;
									}
								}
								if (i == 15) {
									if (Bag::buy_in_T[2].amount > 0) {
										Bag::store[0] = Bag::pos_x;
										Bag::store[1] = Bag::pos_y;
										Bag::store[2] = 15;
										Bag::pos_xy.push_back(Bag::store);
										Bag::bagUI[0] = Bag::buy_in_T[2].name + " x " + std::to_string((int)(Bag::buy_in_T[2].amount));
										Draw::draw(Bag::bagUI, Bag::pos_y, Bag::pos_x);
										Bag::pos_x++;
									}
								}
							}
						}

						if (Bag::pos_xy.size() == 0) {
							Draw::setColor();
							Bag::statment = { "Empty                        " };
							Draw::draw(Bag::statment, 53, 22);
						}
						else {
							Bag::bagUI = Draw::readSpace(53, 2, 1, 29);
							Draw::setColor(246);
							Draw::draw(Bag::bagUI, 53, 2);
							Bag::pos_x = 2;
							Bag::pos_y = 53;
						}
					}

					break;
				}
				if (input == 110) {//n
					Bag::statment = { "                             " };
					Draw::draw(Bag::statment, 53, 22);
					Bag::bagUI = Draw::readSpace(Bag::pos_y, Bag::pos_x, 1, 29);
					Draw::setColor(246);
					Draw::draw(Bag::bagUI, Bag::pos_y, Bag::pos_x);
					break;
				}
			}
			break;
		case 27:
			Draw::setColor();
			Draw::draw(Bag::original_ui, 53, 2);
			return;
		}
		input = _getch();
	}
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

int main() {
	inRange();
	Bag bag;
	Shop shop;
	Draw::draw(pic, 0, 0);
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
	map.setRect(player1.rect);   //Player1
	map.setRect(player2.rect);   //Player2
	map.setRect(player3.rect);   //Palyer3
	map.setRect(enemy1.rect);    //Enemy1
	map.setRect(enemy2.rect);    //Enemy2
	map.setRect(enemy3.rect);
	//map.show();
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

	std::vector<Entity*> Entity_map;
	for (int i = 0; i < roles.size(); i++) {
		roles[i]->setPosDraw(7 + 26 * i, 29);
		Entity_map.push_back(roles[i]);
	}
	for (int i = 0; i < roles.size(); i++) {
		if (roles[i]->inAction) {
			setColor(207);
		}
		draw(roles[i]->output(), roles[i]->xDraw, roles[i]->yDraw);
		setColor();
	}

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
	int wheather_use_focus = 0;
	int Turn_Counted = 1;
	Dice dice;
	/*while (1) {  //while enemy still exist,loop
		for (int i = 0; i < 3; i++) {
			gotoxy(59, 2);
			setColor();
			std::cout << Turn_Counted;
			if (turn[i] == player1.speed) {  //player1 move
				Draw::drawMap(map, player1.rect.x-12, player1.rect.y-25);
				gotoxy(66, 3);
				std::cout << "               ";
				gotoxy(66, 3);
				std::cout << player1.name;
				gotoxy(68, 4);
				std::cout << "          ";

				setColor(10);
				draw(choice_player, 6, 28);
				setColor();
				draw(choice_player, 31, 28);
				draw(choice_player, 56, 28);
				for (int i = 0; i < roles.size(); i++) {
					if (roles[i]->inAction) {
						setColor(207);
					}
					draw(roles[i]->output(), roles[i]->xDraw, roles[i]->yDraw);
					setColor();
				}

				gotoxy(0, 40);
				setColor();
				std::cout << "Do you wnat to use focus?" << std::endl;
				std::cin >> wheather_use_focus;
				dice.action(player1, wheather_use_focus);

				gotoxy(68, 4);
				for (int k = 0; k < dice.result.size(); k++) {
					if (dice.result[k] == 'T') {
						setColor(14);
						std::cout << "T";
					}
					else if(dice.result[k] == 'F') {
						setColor(8);
						std::cout << "F";
					}
				}

				for (int j = dice.movement_points; j > 0; j--) { //how many step player1 can move
					map.nowx = player1.rect.x;
					map.nowy = player1.rect.y;
					map.getinput(1);
					player1.rect.x = map.nowx;
					player1.rect.y = map.nowy;
					Draw::drawMap(map, player1.rect.x - 12, player1.rect.y - 25);
					while ((player1.rect.x == enemy1.rect.x && player1.rect.y == enemy1.rect.y) || (player1.rect.x == enemy2.rect.x && player1.rect.y == enemy2.rect.y) || (player1.rect.x == enemy3.rect.x && player1.rect.y == enemy3.rect.y)) {
						system("CLS");
						setColor(7);
						fight(roles, enemys);
					}
				}
			}
			else if (turn[i] == player2.speed) {  //player2 move
				Draw::drawMap(map, player2.rect.x-12, player2.rect.y-25);
				gotoxy(66, 3);
				std::cout << "               ";
				gotoxy(66, 3);
				setColor();
				std::cout << player2.name;
				gotoxy(68, 4);
				std::cout << "          ";

				draw(choice_player, 6, 28);
				setColor(10);
				draw(choice_player, 31, 28);
				setColor();
				draw(choice_player, 56, 28);

				for (int i = 0; i < roles.size(); i++) {
					if (roles[i]->inAction) {
						setColor(207);
					}
					draw(roles[i]->output(), roles[i]->xDraw, roles[i]->yDraw);
					setColor();
				}

				gotoxy(0, 40);
				setColor();
				std::cout << "Do you wnat to use focus?" << std::endl;
				std::cin >> wheather_use_focus;
				dice.action(player2, wheather_use_focus);

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
					map.nowx = player2.rect.x;
					map.nowy = player2.rect.y;
					map.getinput(2);
					Draw::drawMap(map, player2.rect.x - 12, player2.rect.y - 25);
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
				Draw::drawMap(map, player3.rect.x-12, player3.rect.y-25);
				gotoxy(66, 3);
				std::cout << "               ";
				gotoxy(66, 3);
				setColor();
				std::cout << player3.name;
				gotoxy(68, 4);
				std::cout << "          ";

				draw(choice_player, 6, 28);
				draw(choice_player, 31, 28);
				setColor(10);
				draw(choice_player, 56, 28);

				setColor();
				for (int i = 0; i < roles.size(); i++) {
					if (roles[i]->inAction) {
						setColor(207);
					}
					draw(roles[i]->output(), roles[i]->xDraw, roles[i]->yDraw);
					setColor();
				}

				gotoxy(0, 40);
				setColor();
				std::cout << "Do you wnat to use focus?" << std::endl;
				std::cin >> wheather_use_focus;
				dice.action(player3, wheather_use_focus);

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
					map.nowx = player3.rect.x;
					map.nowy = player3.rect.y;
					map.getinput(3);
					Draw::drawMap(map, player3.rect.x-12, player3.rect.y-25);
					player3.rect.x = map.nowx;
					player3.rect.y = map.nowy;
					while ((player3.rect.x == enemy1.rect.x && player3.rect.y == enemy1.rect.y) || (player3.rect.x == enemy2.rect.x && player3.rect.y == enemy2.rect.y) || (player3.rect.x == enemy3.rect.x && player3.rect.y == enemy3.rect.y)) {
						system("CLS");
						setColor(7);
						fight(roles, enemys);
					}
				}
			}
			Turn_Counted++;
		}
	}

	fight(roles, enemys);

	return 0;*/

	shop.show();
	shop.select_product();

	bag.bag_ui();
	pick_inventory();
}
