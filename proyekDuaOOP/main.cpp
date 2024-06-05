#include "enemy.h"
#include "map.h"
#include "role.h"
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

void fight(Entity& role, Entity& enemy) {
	Draw::setColor();
	system("CLS");
	Draw::draw(fight_ui, 0, 0);
	std::vector<std::string> space = { "               ", "               " };
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
	bool roleFlee = 0;
	bool enemyFlee = 0;
	int  input = -1;
	while (!roleFlee && !enemyFlee && role.vitality > 0 && enemy.vitality > 0) {
		if (input == 27) {
			break;
		}
		if (role.cmp(enemy)) {
			role.mainPhaseStart();
			roleFlee = role.actionForFight(enemy);
			role.addActionTimes();
		}
		else {
			enemy.mainPhaseStart();
			enemyFlee = enemy.actionForEnemy(role);
			enemy.addActionTimes();
		}
		Draw::draw(role.output(), role.xDraw, role.yDraw);
		Draw::draw(enemy.output(), enemy.xDraw, enemy.yDraw);
	}
	std::vector<std::string> end;
	if (roleFlee) {
		end = {
			"------------------------------",
			"|                            |",
			"|          You Flee!         |",
			"|                            |",
			"| Press any bottom to leave  |",
			"------------------------------"
		};
	}
	else if (enemyFlee) {
		end = {
			"------------------------------",
			"|                            |",
			"|         Enemy flee!        |",
			"|                            |",
			"| Press any bottom to leave  |",
			"------------------------------"
		};
	}
	else if (role.vitality == 0 && enemy.vitality > 0) {
		end = {
			"------------------------------",
			"|                            |",
			"|          You Fail!         |",
			"|                            |",
			"| Press any bottom to leave  |",
			"------------------------------"
		};
	}
	else if (role.vitality == 0 && enemy.vitality > 0) {
		end = {
			"------------------------------",
			"|                            |",
			"|          You Win!          |",
			"|                            |",
			"| Press any bottom to leave  |",
			"------------------------------"
		};
	}
	Draw::draw(end, 64, 18);
	input = _getch();
}

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

void Draw_Player_information(std::vector<Entity*>& roles);
void GameLoop(std::vector<Entity*>& roles, std::vector<Entity*>& enemys, Map& map);
void Decide_Turn(std::vector<Entity*>& roles);
void select_players(std::vector<Entity*>& roles, int i);
void show_player_equipment_buff(std::vector<Entity*>& roles);

int main() {
	inRange();
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
	map.setWall();
	map.setShop();
	map.setEvent();
	map.setRect(player1.rect);
	map.setRect(player2.rect);
	map.setRect(player3.rect);
	map.setRect(enemy1.rect);
	map.setRect(enemy2.rect);
	map.setRect(enemy3.rect);

	GameLoop(roles, enemys, map);
}


void Draw_Player_information(std::vector<Entity*>& roles) {
	std::vector<Entity*> Entity_map;
	roles[0]->setPosDraw(7, 29);
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

void select_players(std::vector<Entity*>& roles, int i) {
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

void show_player_equipment_buff(std::vector<Entity*>& roles) {
	std::vector<std::string> buff_name = { "Angry","Dizziness","Poisoned","SpeedUp" };
	for (int i = 0; i < 3; i++) {
		gotoxy(83 + 20*i, 0);
		std::cout << roles[i]->name;
		gotoxy(83 + 20 * i, 1);
		std::cout << "Weapon : " << roles[i]->equip[0].name;
		gotoxy(83 + 20 * i, 2);
		std::cout << "Armour : " << roles[i]->equip[1].name;
		gotoxy(83 + 20 * i, 3);
		std::cout << "Accessory : " << roles[i]->equip[2].name;
		gotoxy(83 + 20 * i, 4);
		std::cout << "Buff : ";
		for (int j = 0; j < roles[i]->buff.size(); j++) {
			if (roles[i]->buff[j] != 0) {
				std::cout << buff_name[j];
				if (j != roles[i]->buff.size() - 1) {
					std::cout << ", ";
				}
			}
		}
	}
}

void GameLoop(std::vector<Entity*>& roles, std::vector<Entity*>& enemys, Map& map) {
	// operate
	char input = _getch();
	int wheather_use_focus = 0;
	int Turn_Counted = 1;
	Dice dice;
	std::vector<Entity*> stay = roles;
	Draw_Player_information(stay);
	show_map_ui();
	Decide_Turn(roles);
	while (input!=27 || roles[0]->vitality != 0 && roles[1]->vitality != 0 && roles[2]->vitality != 0) {  //while enemy still exist,loop
		for (int i = 0; i < 3; i++) {
			if (roles[i]->vitality == 0) {
				continue;
			}
			gotoxy(59, 2);
			setColor();
			std::cout << Turn_Counted;
			Draw::drawMap(map, roles[i]->rect.x - 12, roles[i]->rect.y - 25);
			gotoxy(66, 3);
			std::cout << "               ";
			gotoxy(66, 3);
			std::cout << roles[i]->name;
			gotoxy(68, 4);
			std::cout << "          ";

			int max_movement_points = floor(roles[i]->speed / 10);
			select_players(roles, i);
			Draw_Player_information(stay);
			show_player_equipment_buff(stay);
			setColor();
			gotoxy(53, 5);
			std::cout << "Do you want to use focus?" << std::endl;
			while (1) {
				gotoxy(53, 6);
				std::cin >> wheather_use_focus;

				if (wheather_use_focus < 0 || wheather_use_focus>max_movement_points) {
					gotoxy(53, 7);
					std::cout << "It's not validable,try again." << std::endl;
					gotoxy(53, 6);
					std::cout << "         ";
					gotoxy(53, 6);
					continue;
				}
				else {
					break;
				}
			}
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
				if (roles[i]->vitality == 0) {
					break;
				}
				setColor();
				Draw_Player_information(stay);
				show_player_equipment_buff(stay);
				map.nowx = roles[i]->rect.x;
				map.nowy = roles[i]->rect.y;
				if (roles[i]->name == "chen-yon-fa") {
					map.getinput(*roles[i], 1, roles[0]->rect.x, roles[0]->rect.y, roles[1]->rect.x, roles[1]->rect.y, roles[2]->rect.x, roles[2]->rect.y);
				}
				else if (roles[i]->name == "Alus") {
					map.getinput(*roles[i], 2, roles[0]->rect.x, roles[0]->rect.y, roles[1]->rect.x, roles[1]->rect.y, roles[2]->rect.x, roles[2]->rect.y);
				}
				else if (roles[i]->name == "boring bowling") {
					map.getinput(*roles[i], 3, roles[0]->rect.x, roles[0]->rect.y, roles[1]->rect.x, roles[1]->rect.y, roles[2]->rect.x, roles[2]->rect.y);
				}
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

				//if getinput new position meet enemy, fight
				if (map[map.nowx][map.nowy].type == 'E') {
					int which_enemy = 0;
					if (map.nowx == enemys[0]->rect.x && map.nowy == enemys[0]->rect.y && roles[0]->vitality != 0) {
						system("CLS");
						setColor(7);
						fight(*roles[i], *enemys[0]);
						which_enemy = 0;
					}
					else if (map.nowx == enemys[1]->rect.x && map.nowy == enemys[1]->rect.y && roles[1]->vitality != 0) {
						system("CLS");
						setColor(7);
						fight(*roles[i], *enemys[1]);
						which_enemy = 1;
					}
					else if (map.nowx == enemys[2]->rect.x && map.nowy == enemys[2]->rect.y && roles[2]->vitality != 0) {
						system("CLS");
						setColor(7);
						fight(*roles[i], *enemys[2]);
						which_enemy = 2;
					}
					system("CLS");
					show_map_ui();
					gotoxy(59, 2);
					setColor();
					std::cout << Turn_Counted;
					gotoxy(66, 3);
					std::cout << "               ";
					gotoxy(66, 3);
					std::cout << roles[i]->name;
					gotoxy(68, 4);
					std::cout << "          ";
					Draw_Player_information(stay);
					show_player_equipment_buff(stay);
					if (roles[i]->vitality == 0) {
						break;
					}
					select_players(roles, i);
					if (enemys[which_enemy]->vitality == 0) {   //enemy die
						map.set_new_rect_type(map.nowx, map.nowy, '.');
						map.set_new_rect_type(map.nowx, map.nowy, i+49);
						roles[i]->rect.x = map.nowx;
						roles[i]->rect.y = map.nowy;
						Draw::drawMap(map, roles[i]->rect.x - 12, roles[i]->rect.y - 25);

					}
					else {  //enemy doesn't die
						map.set_new_rect_type(map.nowx, map.nowy, 'E');
						map.set_new_rect_type(roles[i]->rect.x, roles[i]->rect.y, i + 49);
						Draw::drawMap(map, roles[i]->rect.x - 12, roles[i]->rect.y - 25);
					}

				}
				else {
					roles[i]->rect.x = map.nowx;
					roles[i]->rect.y = map.nowy;
					Draw::drawMap(map, roles[i]->rect.x - 12, roles[i]->rect.y - 25);
				}
			}
			Turn_Counted++;
		}
	}
	return;
}