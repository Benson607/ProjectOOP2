#include "map.h"
#include <conio.h>

using namespace Draw;

Map::Map() :std::vector<std::vector<Rect>>(50, std::vector<Rect>(140, Rect(5))) {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 140; j++) {
			this[0][i][j].x = i;
			this[0][i][j].y = j;
		}
	}
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
	for (int i = 0; i < 5; i++) {
		int x = rand() % 50;
		int y = rand() % 140;
		if (this[0][x][y].type == '.') {
			this[0][x][y] = Rect(7);
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
			case 'R'://random events
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

void Map::getinput(int player, int player1_x, int player1_y, int player2_x, int player2_y, int player3_x, int player3_y) {
	int input;
	bool can_walk = 0;
	if (player == 1) {
		if (player1_x == player2_x && player1_y == player2_y) //if Player1's position = Player2's position
			this[0][nowx][nowy].type = '2';
		else if (player1_x == player3_x && player1_y == player3_y) //if Player1's position = Player3's position
			this[0][nowx][nowy].type = '3';
		else if (this[0][nowx][nowy].type == 'E')
			this[0][nowx][nowy].type == 'E';
		else
			this[0][nowx][nowy].type = '.';   //turn the start postition to '.' rect
	}
	else if (player == 2) {
		if (player2_x == player1_x && player2_y == player1_y) //if Player2's position = Player1's position
			this[0][nowx][nowy].type = '1';
		else if (player2_x == player3_x && player2_y == player3_y) //if Player2's position = Player3's position
			this[0][nowx][nowy].type = '3';
		else if (this[0][nowx][nowy].type == 'E')
			this[0][nowx][nowy].type == 'E';
		else
			this[0][nowx][nowy].type = '.';   //turn the start postition to '.' rect
	}
	else if (player == 3) {
		if (player3_x == player1_x && player3_y == player1_y) //if Player3's position = Player1's position
			this[0][nowx][nowy].type = '1';
		else if (player3_x == player2_x && player3_y == player2_y) //if Player3's position = Player2's position
			this[0][nowx][nowy].type = '2';
		else if (this[0][nowx][nowy].type == 'E')
			this[0][nowx][nowy].type == 'E';
		else
			this[0][nowx][nowy].type = '.';   //turn the start postition to '.' rect
	}

	do {
		input = _getch();
		switch (input)
		{
		case 119:  //w
			if (nowx > 0 && this[0][nowx - 1][nowy].type != ' ') {
				nowx -= 1;
				can_walk = 1;
			}
			else
				can_walk = 0;
			break;
		case 97:  //a
			if (nowy > 0 && this[0][nowx][nowy - 1].type != ' ') {
				nowy -= 1;
				can_walk = 1;
			}
			else
				can_walk = 0;
			break;
		case 115:  //s
			if (nowx < 50 && this[0][nowx + 1][nowy].type != ' ') {
				nowx += 1;
				can_walk = 1;
			}
			else
				can_walk = 0;
			break;
		case 100:  //d
			if (nowy < 140 && this[0][nowx][nowy + 1].type != ' ') {
				nowy += 1;
				can_walk = 1;
			}
			else
				can_walk = 0;
			break;

		case 105:  //i
			system("CLS");
			//open backpack
			break;

		default:
			can_walk = 0;
			break;
		}
	} while (can_walk != 1);

	if (this[0][nowx][nowy].type =='E')  //if new position meet enemy, return, and fight
		return;

	this[0][nowx][nowy].type = player + 48;

	if (this[0][nowx][nowy].type == '$') {
		system("CLS");
		//Open Shop
		return;
	}
	return;
}

void Map::set_new_rect_type(int x,int y,char T) {
	this[0][x][y].type = T;
}
