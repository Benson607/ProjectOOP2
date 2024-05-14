#include "draw.h"

void Draw::draw(std::vector<std::string> out, int x, int y) {
	gotoxy(x, y);
	for (std::string i : out) {
		std::cout << i;
		y++;
		gotoxy(x, y);
	}
}

void Draw::drawMap(std::vector<std::vector<Rect>> map, int fromx, int fromy, int x, int y, int sizex, int sizey) {
	gotoxy(x, y);
	for (int i = 0; i < sizex; i++) {
		for (int j = 0; j < sizey; j++) {
			switch (map[i][j].type) {
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
			case '$':
				setColor(240);
				break;
			default:
				break;
			}
			std::cout << map[i][j].type;
			setColor();
		}
		y++;
		gotoxy(x, y);
	}
}

void Draw::gotoxy(int x, int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD  scrn;
	scrn.X = x;
	scrn.Y = y;
	SetConsoleCursorPosition(hConsole, scrn);
}

void Draw::inRange() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	GetConsoleScreenBufferInfo(hConsole, &bufferInfo);
	int right = bufferInfo.srWindow.Right;
	int bottom = bufferInfo.srWindow.Bottom;
	if (right < 155 || bottom < 40) {
		system("CLS");
		std::cout << "Please enlarge the window to its maximum size or reduce the font size";
	}
	else {
		return;
	}
	do {
		GetConsoleScreenBufferInfo(hConsole, &bufferInfo);
		if (right != bufferInfo.srWindow.Right || bottom != bufferInfo.srWindow.Bottom) {
			right = bufferInfo.srWindow.Right;
			bottom = bufferInfo.srWindow.Bottom;
			if (right < 155 || bottom < 40) {
				system("CLS");
				std::cout << "Please enlarge the window to its maximum size or reduce the font size";
			}
		}
	} while (bufferInfo.srWindow.Right < 155 || bufferInfo.srWindow.Bottom < 40);
}

void Draw::setColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

std::string Draw::read(int x, int y, DWORD len) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	wchar_t outstr[100] = { '\0' };
	COORD pos;
	pos.X = x;
	pos.Y = y;
	ReadConsoleOutputCharacter(hConsole, outstr, len, pos, &len);
	std::string ans;
	for (int i = 0; i < (int)len; i++) {
		ans.push_back((char)outstr[i]);
	}
	return ans;
}

std::vector<std::string> Draw::readSpace(int x, int y, int high, DWORD len) {
	std::vector<std::string> ans(0);
	for (int i = 0; i < high; i++) {
		ans.push_back(read(x, y, len));
		y++;
	}
	return ans;
}
