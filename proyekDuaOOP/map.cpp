#include "map.h"

using namespace Draw;

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