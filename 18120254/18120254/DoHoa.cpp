#include "DoHoa.h"
// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int column, int line) {
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
