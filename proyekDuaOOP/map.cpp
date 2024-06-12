#include "map.h"

#include <conio.h>

#include "dice.h"
#include "draw.h"
#include "enemy.h"
#include "role.h"
#include "shop.h"

using namespace Draw;

void pick_inventory(Entity& entity);

Shop shop;

std::vector<std::string> map_ui_again = {
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
void show_map_ui_again() {
	draw(map_ui_again, 0, 0);
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

void show_partial_ui() {
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

Map::Map() : std::vector<std::vector<Rect>>(50, std::vector<Rect>(140, Rect(5))) {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 140; j++) {
			this[0][i][j].x = i;
			this[0][i][j].y = j;
		}
	}
	Bag bag;
}

void Map::setRect(Rect& obj) {
	do {
		obj.setRandomPos();
	} while (this[0][obj.x][obj.y].type != '.');
	this[0][obj.x][obj.y] = obj;
}

void Map::setWall() {
	for (int i = 0; i < 40; i++) {
		int x = rand() % 50;
		int y = rand() % 140;
		if (this[0][x][y].type == '.') {
			this[0][x][y] = Rect(0);
		}
		else {
			i--;
		}
	}
}

void Map::setShop() {
	for (int i = 0; i < 3; i++) {
		int x = rand() % 50;
		int y = rand() % 140;
		if (this[0][x][y].type == '.') {
			this[0][x][y] = Rect(6);
		}
		else {
			i--;
		}
	}
}

void Map::setEvent() {
	for (int i = 0; i < 3; i++) {
		int x = rand() % 50;
		int y = rand() % 140;
		if (this[0][x][y].type == '.') {
			this[0][x][y].type = '?';
		}
		else {
			i--;
		}
	}
}

void Map::show() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 140; j++) {
			switch (this[0][i][j].type) {
			case ' ':
				setColor(136);
				break;
			case '1':
				setColor(230);
				break;
			case '2':
				setColor(230);
				break;
			case '3':
				setColor(230);
				break;
			case 'E':
				setColor(236);
				break;
			case '.':
				setColor(224);
				break;
			case '?':  // random events
				setColor(211);
			case '$':
				setColor(240);
				break;
			default:
				break;
			}
			std::cout << this[0][i][j].type;
			setColor();
		}
		std::cout << std::endl;
	}
}

void Map::getinput(Entity& entity, int player, std::vector<Entity*>& stay) {
	int  input;
	bool can_walk = 0;

	if (player == 1) {
		if (stay[0]->rect.x == stay[1]->rect.x && stay[0]->rect.y == stay[1]->rect.y && stay[1]->vitality != 0)  // if Player1's position = Player2's position
			this[0][nowx][nowy].type = '2';
		else if (stay[0]->rect.x == stay[2]->rect.x && stay[0]->rect.y == stay[2]->rect.y && stay[2]->vitality != 0)  // if Player1's position = Player3's position
			this[0][nowx][nowy].type = '3';
		else if (this[0][nowx][nowy].type == 'E')
			this[0][nowx][nowy].type = 'E';
		else if (this[0][nowx][nowy].type == 'T')
			this[0][nowx][nowy].type = 'T';
		else
			this[0][nowx][nowy].type = '.';  // turn the start postition to '.' rect
	}
	else if (player == 2) {
		if (stay[1]->rect.x == stay[0]->rect.x && stay[1]->rect.y == stay[0]->rect.y && stay[0]->vitality != 0)  // if Player2's position = Player1's position
			this[0][nowx][nowy].type = '1';
		else if (stay[1]->rect.x == stay[2]->rect.x && stay[1]->rect.y == stay[2]->rect.y && stay[2]->vitality != 0)  // if Player2's position = Player3's position
			this[0][nowx][nowy].type = '3';
		else if (this[0][nowx][nowy].type == 'E')
			this[0][nowx][nowy].type = 'E';
		else if (this[0][nowx][nowy].type == 'T')
			this[0][nowx][nowy].type = 'T';
		else
			this[0][nowx][nowy].type = '.';  // turn the start postition to '.' rect
	}
	else if (player == 3) {
		if (stay[2]->rect.x == stay[0]->rect.x && stay[2]->rect.y == stay[0]->rect.y && stay[0]->vitality != 0)  // if Player3's position = Player1's position
			this[0][nowx][nowy].type = '1';
		else if (stay[2]->rect.x == stay[1]->rect.x && stay[2]->rect.y == stay[1]->rect.y && stay[1]->vitality != 0)  // if Player3's position = Player2's position
			this[0][nowx][nowy].type = '2';
		else if (this[0][nowx][nowy].type == 'E')
			this[0][nowx][nowy].type = 'E';
		else if (this[0][nowx][nowy].type == 'T')
			this[0][nowx][nowy].type = 'T';
		else
			this[0][nowx][nowy].type = '.';  // turn the start postition to '.' rect
	}

	do {
		input = _getch();
		switch (input) {
		case 119:  // w
			if (nowx > 0) {
				if (this[0][nowx - 1][nowy].type == '$') {
					system("CLS");
					shop.show();
					shop.select_product();
					system("CLS");
					show_map_ui_again();
					this[0][nowx][nowy].type = player + 48;
					can_walk = 1;
					return;
				}
				else if (nowx > 0 && this[0][nowx - 1][nowy].type != ' ') {
					nowx -= 1;
					can_walk = 1;
				}
				else {
					can_walk = 0;
				}
			}
			break;
		case 97:  // a
			if (nowy > 0) {
				if (this[0][nowx][nowy - 1].type == '$') {
					system("CLS");
					shop.show();
					shop.select_product();
					system("CLS");
					show_map_ui_again();
					this[0][nowx][nowy].type = player + 48;
					can_walk = 1;
					return;
				}
				else if (this[0][nowx][nowy - 1].type != ' ') {
					nowy -= 1;
					can_walk = 1;
				}
				else {
					can_walk = 0;
				}
			}
			break;
		case 115:  // s
			if (nowx < 49) {
				if (this[0][nowx + 1][nowy].type == '$') {
					system("CLS");
					shop.show();
					shop.select_product();
					system("CLS");
					show_map_ui_again();
					this[0][nowx][nowy].type = player + 48;
					can_walk = 1;
					return;
				}
				else if (this[0][nowx + 1][nowy].type != ' ') {
					nowx += 1;
					can_walk = 1;
				}
				else {
					can_walk = 0;
				}
			}
			break;
		case 100:  // d
			if (nowy < 139) {
				if (this[0][nowx][nowy + 1].type == '$') {
					system("CLS");
					shop.show();
					shop.select_product();
					system("CLS");
					show_map_ui_again();
					this[0][nowx][nowy].type = player + 48;
					can_walk = 1;
					return;
				}
				else if (this[0][nowx][nowy + 1].type != ' ') {
					nowy += 1;
					can_walk = 1;
				}
				else {
					can_walk = 0;
				}
			}
			break;
		case 105:  // i
			Bag::bag_ui();
			pick_inventory(entity);
			if (entity.teleportScroll) {
				nowx = entity.rect.x;
				nowy = entity.rect.y;
			}
			show_partial_ui();
			can_walk = 0;
			break;
		case 27:
			//end_game = 1;
			//return;
			break;
		default:
			can_walk = 0;
			break;
		}
	} while (can_walk != 1);

	if (this[0][nowx][nowy].type == 'E')  // if new position meet enemy, return, and fight
		return;

	else if (this[0][nowx][nowy].type == 'T') {
		stay_tent_x = nowx;
		stay_tent_y = nowy;
		this[0][nowx][nowy].type = player + 48;
	}

	if (entity.teleportScroll) {
		nowx = entity.rect.x;
		nowy = entity.rect.y;
	}
	else {
		this[0][nowx][nowy].type = player + 48;
	}

	return;
}

void Map::set_new_rect_type(int x, int y, char T) {
	this[0][x][y].type = T;
}

void pick_inventory(Entity& entity) {
	int input = _getch();
	while (input != 27) {
		gotoxy(54, 2);
		switch (input) {
		case 119:  // w
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
		case 115:  // s
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
		case 114:  // r
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
				input = _getch();
				if (input == 121 && Bag::pos_x < Bag::pos_xy.size() + 2) {
					Bag::statment = { "Used!                        " };
					Draw::draw(Bag::statment, 53, 22);

					int flag = 0;
					for (int i = 0; i < Bag::pos_xy.size(); i++) {
						if (Bag::pos_x == Bag::pos_xy[i][0] && Bag::pos_y == Bag::pos_xy[i][1] && Bag::pos_xy[i][2] < 13) {
							entity.use(Bag::buy_in_E[Bag::pos_xy[i][2]]);
							Bag::buy_in_E[Bag::pos_xy[i][2]].amount--;
							if (Bag::buy_in_E[Bag::pos_xy[i][2]].amount == 0) {
								flag = 1;
							}
							else {
								Draw::setColor(246);
								Bag::bagUI[0] = Bag::buy_in_E[Bag::pos_xy[i][2]].name + " x "
									+ std::to_string((int)(Bag::buy_in_E[Bag::pos_xy[i][2]].amount));
								Draw::draw(Bag::bagUI, Bag::pos_y, Bag::pos_x);
								Bag::bagUI = Draw::readSpace(Bag::pos_y, Bag::pos_x, 1, 29);
								Draw::draw(Bag::bagUI, Bag::pos_y, Bag::pos_x);
							}
							//.use(Bag::buy_in_E[Bag::pos_xy[i][2]]);
							break;
						}
						else if (Bag::pos_x == Bag::pos_xy[i][0] && Bag::pos_y == Bag::pos_xy[i][1] && Bag::pos_xy[i][2] == 13) {
							entity.use(Bag::buy_in_T[0]);
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
							entity.use(Bag::buy_in_T[1]);
							entity.teleportScroll = true;
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
							entity.use(Bag::buy_in_T[2]);
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
						else if (Bag::pos_x == Bag::pos_xy[i][0] && Bag::pos_y == Bag::pos_xy[i][1] && Bag::pos_xy[i][2] == 16) {
							entity.use(Bag::buy_in_T[3]);
							Bag::buy_in_T[3].amount--;
							if (Bag::buy_in_T[3].amount == 0) {
								flag = 1;
							}
							else {
								Draw::setColor(246);
								Bag::bagUI[0] = Bag::buy_in_T[3].name + " x " + std::to_string((int)(Bag::buy_in_T[3].amount));
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
						Bag::statment = {
						  "___________Helper____________", "Press W,S to select items    ", "Press R to select the one you",
						  "want to use                  ", "Press Y or N to confirm      " };
						Draw::draw(Bag::statment, 53, 23);
						Bag::pos_x = 2;
						Bag::pos_y = 53;

						for (int i = 0; i < 17; i++) {
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
								if (i == 16) {
									if (Bag::buy_in_T[3].amount > 0) {
										Bag::store[0] = Bag::pos_x;
										Bag::store[1] = Bag::pos_y;
										Bag::store[2] = 16;
										Bag::pos_xy.push_back(Bag::store);
										Bag::bagUI[0] = Bag::buy_in_T[3].name + " x " + std::to_string((int)(Bag::buy_in_T[3].amount));
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
				if (input == 110) {  // n
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
	if (input == 27) {
		Draw::setColor();
		Draw::draw(Bag::original_ui, 53, 2);
		return;
	}
}