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
	g.dropBlock(1);
	cout << g;
	g.nextBlock(1);
	g.rotateBlock(1, true);
	g.moveBlock(1, "right");
	cout << g;
	g.dropBlock(1);
	cout << g;
	/*
	g.moveBlock(1, "right");
	g.moveBlock(1, "right");
	g.moveBlock(1, "right");
	g.moveBlock(1, "right");
	g.moveBlock(1, "right");
	cout << g;
	g.rotateBlock(1, false);
	cout << g;
	g.dropBlock(1);
	cout << g;
	*/
}
