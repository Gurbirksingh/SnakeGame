#include "control.h"

// set the direction for the snake
void Control::setDir(char key) {

	switch (key) {
	case KEY_UP:
		if (dir != 2) dir = 0;
		break;
	case KEY_RIGHT:
		if (dir != 3) dir = 1;
		break;
	case KEY_DOWN:
		if (dir != 4) dir = 2;
		break;
	case KEY_LEFT:
		if (dir != 5) dir = 3;
		break;
	}
}