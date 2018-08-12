#pragma once

#include <iostream>
#include <conio.h>
#include <windows.h>

// predefined Keyboard Key Values
#define KEY_UP		72
#define KEY_DOWN	80
#define KEY_LEFT	75
#define KEY_RIGHT	77

// Direction based in keyboard input
class Control {

protected:

	int dir = 0;

	void setDir(char key);
};
