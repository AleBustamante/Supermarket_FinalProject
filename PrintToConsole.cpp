#include "PrintToConsole.h"

void print::goToXY(Vector2 coordenates){
	COORD pos = { coordenates.x, coordenates.y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void print::setCursorToInputPos(){
	goToXY({ 0, INPUT_POS_Y });
}

void print::setCursorToOutputPos(){
	goToXY({ 0, OUTPUT_POS_Y });
}

void print::setColor(WORD color){

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	
}

void print::setDefaultWindowSize(){
	HWND hwnd = GetConsoleWindow();
	RECT coordenates = { ORIGIN_X, ORIGIN_Y, SCREEN_WIDHT - ORIGIN_X, SCREEN_HEIGHT - ORIGIN_Y}; //{TopLeft.x , TopLeft.y , BottomRight.x , BottomRigh.y}
	MoveWindow(hwnd, coordenates.left, coordenates.top, coordenates.right - coordenates.left, coordenates.bottom - coordenates.top, TRUE);
}

void print::printBorders(WORD color){
	setColor(color);
	Vector2 cursor = ORIGIN_POS;
	goToXY(cursor);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < CURSOR_WIDTH; j++) {
			cout << ' ';
		}
		cursor.y++;
		goToXY(cursor);
	}
	setColor(7);
	
}

void print::printTitle(const string& title){
	setColor(BACKGROUND_BLUE | WHITE);
	goToXY(TITLE_POS);
	int whiteSpaces = CURSOR_WIDTH - title.size();
	for (int i = 0; i < CURSOR_WIDTH; i++) {
		cout << "*";
	}
	for (int i = 0; i < whiteSpaces / 2; i++) {
		cout << " ";
	}
	cout << title;
	for (int i = 0; i < whiteSpaces / 2; i++) {
		cout << " ";
	}
	for (int i = 0; i < CURSOR_WIDTH; i++) {
		cout << "*";
	}
	setColor(WHITE);
	setCursorToInputPos();
}

void print::printHints(const string& hint1, const string& hint2, const string& hint3){
	setColor(BACKGROUND_BLUE | WHITE);
	goToXY({0, CURSOR_HEIGHT});
	if (hint2 == "") {

	}
	int whiteSpaces = (CURSOR_WIDTH - hint1.size() - hint2.size() - hint3.size())/3;
	for (int i = 0; i < CURSOR_WIDTH; i++) {
		cout << "-";
	}
	for (int i = 0; i < whiteSpaces; i++) {
		cout << " ";
	}
	cout << hint1;
	for (int i = 0; i < whiteSpaces; i++) {
		cout << " ";
	}
	cout << hint2;
	for (int i = whiteSpaces*2 + hint1.size() + hint2.size(); i < CURSOR_WIDTH; i++) {
		cout << " ";
	}
	cout << hint3;
	for (int i = 0; i < CURSOR_WIDTH; i++) {
		cout << "-";
	}
	setColor(WHITE);
	setCursorToInputPos();
}

