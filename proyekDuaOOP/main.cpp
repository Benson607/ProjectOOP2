#include <conio.h>

#include "draw.h"
#include "enemy.h"
#include "map.h"
#include "role.h"
#include "dice.h"
#include "shop.h"

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

std::vector<std::string> fight_ui = {
  "|-------------------------------------------------------------------------------------------------------------------------------------|-------------------|",
  "|                                                                                                                                     |                   |",
  "|                                                                                                                                     |                   |",
  "|                                                                                                                                     |                   |",
  "|                                                                                                                                     |                   |",
  "|                                                                                                                                     |                   |",
  "|                                                                                                                                     |                   |",
  "|                                                                                                                                     |                   |",
  "|                                                                                                                                     |                   |",
  "|                                                                                                                                     |                   |",
  "|-------------------------------------------------------------------------------------------------------------------------------------|-------------------|",
  "|                                                                                                                                                         |",
  "|                                                                                                                                                         |",
  "|                                                                                                                                                         |",
  "|                                                                                                                                                         |",
  "|                                                                                                                                                         |",
  "|                                                                                                                                                         |",
  "|                                                                                                                                                         |",
  "|                                                                                                                                                         |",
  "|                                                                                                                                                         |",
  "|                                                                                                                                                         |",
  "|                                                                                                                                                         |",
  "|                                                                                                                                                         |",
  "|                                                                                                                                                         |",
  "|                                                                                                                                                         |",
  "|                                                                                                                                                         |",
  "|                                                                                                                                                         |",
  "|                                                                                                                                                         |",
  "|-------------------|-------------------------------------------------------------------------------------------------------------------------------------|",
  "|                   |                                                                                                                                     |",
  "|                   |                                                                                                                                     |",
  "|                   |                                                                                                                                     |",
  "|                   |                                                                                                                                     |",
  "|                   |                                                                                                                                     |",
  "|                   |                                                                                                                                     |",
  "|                   |                                                                                                                                     |",
  "|                   |                                                                                                                                     |",
  "|                   |                                                                                                                                     |",
  "|-------------------|-------------------------------------------------------------------------------------------------------------------------------------|" };

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
			else if (Bag::pos_x < Bag::pos_xy.size() + 2) {
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
				if (input == 121 && Bag::pos_x < Bag::pos_xy.size() + 2) {
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

void fight2(Entity& role, Entity& enemy) {
	system("CLS");
	Draw::draw(fight_ui, 0, 0);
	std::vector<std::string> space = {
			"               ",
			"               "
	};
	role.setPosDraw(1, 29);
	enemy.setPosDraw(135, 1);
	Draw::draw(role.output(), role.xDraw, role.yDraw);
	Draw::draw(enemy.output(), enemy.xDraw, enemy.yDraw);
	role.actionTimes = -1;
	role.addActionTimes();
	enemy.actionTimes = -1;
	enemy.addActionTimes();
	if (role.cmp(enemy)) {
		Draw::gotoxy(1, 20);
		std::cout << role.name;
		Draw::gotoxy(1, 21);
		std::cout << enemy.name;
	}
	else {
		Draw::gotoxy(1, 20);
		std::cout << enemy.name;
		Draw::gotoxy(1, 21);
		std::cout << role.name;
	}
	bool flee = 0;
	int input = -1;
	while (!flee) {
		if (input == 27) {
			break;
		}
		if (role.cmp(enemy)) {
			flee = role.actionForFight(enemy);
			role.addActionTimes();
		}
		else {
			flee = enemy.actionForFight(role);
			enemy.addActionTimes();
		}
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
	Draw::draw(map_ui, 0, 0);
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
		Draw::draw(roles[i]->output(), roles[i]->xDraw, roles[i]->yDraw);
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

	shop.show();
	shop.select_product();

	bag.bag_ui();
	pick_inventory();

	fight2(player2, enemy1);
}
