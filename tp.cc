#include "grid.h"
#include "cell.h"
#include <iostream>
using namespace std;

int main() {
	Grid g;
	cout << g;
	g.nextBlock(1);
	cout << g;
	g.rotateBlock(1, true);
	cout << g;
	g.moveBlock(1, "right");
	g.moveBlock(1, "down");
	g.moveBlock(1, "down");
	g.moveBlock(1, "down");
	g.moveBlock(1, "down");
	g.moveBlock(1, "down");
	g.moveBlock(1, "down");
	g.moveBlock(1, "down");
	cout << g;
	/*
	g.moveBlock(1, "left");
	cout << g;
	g.moveBlock(1, "down");
	g.moveBlock(1, "left");
	cout << g;
	*/
}
