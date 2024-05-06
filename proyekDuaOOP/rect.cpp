#include "rect.h"
#include <stdlib.h>

Rect::Rect() {
	type = ' ';
	x = rand() % 140;
	y = rand() % 50;
}

Rect::Rect(int type) {
	x = rand() % 140;
	y = rand() % 50;
	this->type = 0;
	if (type == 0) {
		this->type = ' ';
	}
	else if(type == 1){
		this->type = '1';
	}
	else if (type == 2) {
		this->type = '2';
	}
	else if (type == 3) {
		this->type = '3';
	}
	else if (type == 4) {
		this->type = 'E';
	}
	else if (type == 5) {
		this->type = '.';
	}
	else if (type == 6) {
        this->type = '$';
    }
}

void Rect::setRandomPos() {
	x = rand() % 140;
	y = rand() % 50;
}
