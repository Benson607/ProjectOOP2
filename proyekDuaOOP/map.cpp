#include "map.h"

void setWindowSize() {
	
}

void SetColor(int color = 7) {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

Map::Map() :std::vector<std::vector<Rect>>(140, std::vector<Rect>(50, Rect(5))) {

}

void Map::setRect(Rect obj) {
	do {
		obj.setRandomPos();
	} while (this[0][obj.x][obj.y].type != '.');
	this[0][obj.x][obj.y] = obj;
}

void Map::setWall() {
	for (int i = 0; i < 5; i++) {
		int x = rand() % 140;
		int y = rand() % 50;
		if (this[0][x][y].type == '.') {
			this[0][x][y] = Rect(0);
		}
		else {
			i--;
		}
	}
}

void Map::show() {
	for (int i = 0; i < 140; i++) {
		for (int j = 0; j < 50; j++) {
			switch (this[0][i][j].type) {
			case ' ':
				SetColor(136);
				break;
			case '1':
				SetColor(230);
				break;
			case '2':
				SetColor(230);
				break;
			case '3':
				SetColor(230);
				break;
			case 'E':
				SetColor(236);
				break;
			case '.':
				SetColor(224);
				break;
			default:
				break;
			}
			std::cout << this[0][i][j].type;
			SetColor();
		}
		std::cout << std::endl;
	}
}