#include "map.h"

Map::Map():std::vector<std::vector<Rect>>(140,std::vector<Rect>(50,Rect(5))) {
	
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
			std::cout << this[0][i][j].type;
		}
		std::cout << std::endl;
	}
}