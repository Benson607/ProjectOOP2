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
	for (int i = 0; i < 5; i++) {
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
				//setColor(211);
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

void Map::getinput(int player) {
	int input = _getch();
	this[0][nowx][nowy].type = '.';   //turn the start postition to '.' rect
	switch (input)
	{
	case 119:  //w
		if (nowx > 0 && this[0][nowx-1][nowy].type != ' ') {
			nowx -= 1;
		}
		break;
	case 97:  //a
		if (nowy > 0 && this[0][nowx][nowy-1].type != ' ') {
			nowy -= 1;
		}
		break;
	case 115:  //s
		if (nowx < 50 && this[0][nowx+1][nowy].type != ' ') {
			nowx += 1;
		}
		break;
	case 100:  //d
		if (nowy < 140 && this[0][nowx][nowy+1].type != ' ') {
			nowy += 1;
		}
		break;

	case 105:  //i
		//open backpack
		break;
	default:
		break;
	}
	this[0][nowx][nowy].type = player + 48;
	if (this[0][nowx][nowy].type == '$') {
		//Open Shop
	}
}
