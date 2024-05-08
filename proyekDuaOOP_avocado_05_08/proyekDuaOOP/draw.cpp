#include "draw.h"

using namespace std;

void Draw::draw(std::vector<std::string> out, int x, int y) {
	gotoxy(x, y);
	for (string i : out) {
		cout << i;
		y++;
		gotoxy(x, y);
	}
}

void Draw::gotoxy(int x, int y)
{
	COORD scrn;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = x; scrn.Y = y;
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
		cout << "Please enlarge the window to its maximum size or reduce the font size";
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
				cout << "Please enlarge the window to its maximum size or reduce the font size";
			}
		}
	} while (bufferInfo.srWindow.Right < 155 || bufferInfo.srWindow.Bottom < 40);
}

void Draw::setColor(int color) {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}