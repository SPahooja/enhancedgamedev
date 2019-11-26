#ifndef STATE_H
#define STATE_H

enum class Position {MainMap1, MainMap2, NextMap1, NextMap2};

struct State {
	int row, col;
	char disp;
	Position p;
};

#endif
