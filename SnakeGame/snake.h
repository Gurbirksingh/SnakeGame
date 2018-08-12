#pragma once

#include "control.h"

#include <iostream>

// Inherited Snake class from Control class
class Snake : public Control {

	static const int layoutWidth = 20;
	static const int layoutHeight = 20;
	static const int size = layoutWidth * layoutHeight;

	int layout[layoutWidth * layoutHeight];

	int faceX = 0;
	int faceY = 0;

	int length = 3;
	bool running = false;

	void initializeLayout();
	void createFood();
	char getLayoutValue(int value);
	void update();
	void move(int x, int y);
	void resetWindow();
	void displayLayout();

public:
	// overloaded stream to print layout
	friend std::ostream& operator<<(std::ostream& os, const int layout[]);
	// starts the Game
	void start();
};
