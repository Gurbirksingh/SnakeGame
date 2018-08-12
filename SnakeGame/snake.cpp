#include "snake.h"
// run the game
void Snake::start()
{
	initializeLayout();
	running = true;
	while (running) {
		if (_kbhit()) setDir(_getch());
		update();
		resetWindow();
		displayLayout();
		Sleep(300);
	}
	std::cout << "\n\tYOU LOST! GAME OVER!\n\tPoints: " << length;
	std::cin.ignore();
}
// moves the snake 
void Snake::move(int x, int y) {
	int newx = faceX + x;
	int newy = faceY + y;

	if (layout[newx + newy * layoutWidth] == -2) {
		length++;
		createFood();
	}

	else if (layout[newx + newy * layoutWidth] != 0) {
		running = false;
	}
	faceX = newx;
	faceY = newy;
	layout[faceX + faceY * layoutWidth] = length + 1;

}
//clear screen
void Snake::resetWindow() {
	system("cls");
}
// generate the food
void Snake::createFood() {
	int x = 0;
	int y = 0;
	do {
		x = rand() % (layoutWidth - 2) + 1;
		y = rand() % (layoutHeight - 2) + 1;
	} while (layout[x + y * layoutWidth] != 0);

	// generate the new Food Item
	layout[x + y * layoutWidth] = -2;
}
// update the screen
void Snake::update() {

	switch (dir) {
	case 0: move(-1, 0);
		break;
	case 1: move(0, 1);
		break;
	case 2: move(1, 0);
		break;
	case 3: move(0, -1);
		break;
	}

	for (int i = 0; i < size; i++) {
		if (layout[i] > 0) layout[i]--;
	}
}
// Intialize the layout array
void Snake::initializeLayout()
{
	for (int i = 0; i < layoutWidth; ++i) {
		for (int j = 0; j < layoutHeight; ++j) {
			layout[i * layoutWidth + j] = 0;
		}
	}

	faceX = layoutWidth / 2;
	faceY = layoutHeight / 2;
	layout[faceX + faceY * layoutWidth] = 1;

	for (int x = 0; x < layoutWidth; ++x) {
		layout[x] = -1;
		layout[x + (layoutHeight - 1) * layoutWidth] = -1;
	}

	for (int y = 0; y < layoutHeight; y++) {
		layout[0 + y * layoutWidth] = -1;
		layout[(layoutWidth - 1) + y * layoutWidth] = -1;
	}

	createFood();
}
// Prints the Layout Array on screen
void Snake::displayLayout()
{
	for (int x = 0; x < layoutWidth; ++x) {
		for (int y = 0; y < layoutHeight; ++y) {

			std::cout << getLayoutValue(layout[x + y * layoutWidth]);
		}

		std::cout << std::endl;
	}
}
//Returns character based on value of layout array 
char Snake::getLayoutValue(int value)
{
	if (value > 0) return 'o';

	switch (value) {
	case -1:
		return 'X';
	case -2:
		return 'O';
	}
}

std::ostream& operator << (std::ostream& os, const int layout[])
{
	for (int x = 0; x < 20; ++x) {
		for (int y = 0; y < 20; ++y) {
			os << (layout[x + y * 20]);
		}
		os << std::endl;
	}
	return os;
}
