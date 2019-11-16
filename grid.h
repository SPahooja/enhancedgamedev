#ifndef GRID_H
#define GRID_H
#include "cell.h"
#include <iostream>
#include <fstream>
#include <vector>

class Cell;
class GraphicDisplay;

class Grid {
	std::vector<std::vector<Cell*>> map;
	std::vector<Piece*> moves;
	Level *lp;
	GraphicDisplay *gd;
	int highscore;
	int curscore;
	public:
		Grid(int lev = 1);
		void nextBlock();
		void moveBlock(std::string dir);
		void rotateBlock(bool clock);
		void dropBlock();
	friend std::ostream &operator<<(std::ostream &out, const Grid &g);
}
