#ifndef GRID_H
#define GRID_H
#include "cell.h"
#include <iostream>
#include <fstream>
#include <vector>

class Cell;
class GraphicDisplay {};
class Piece {};
class Level {};

class Grid {
	std::vector<std::vector<Cell*>> map1;
	std::vector<Piece*> move1;
	Level *lp1;
	int curscore1;
	int lev1;
	std::vector<std::vector<Cell*>> map2;
	std::vector<Piece*> move2;
	Level *lp2;
	int curscore2;
	int lev2;
	GraphicDisplay *gd;
	public:
		Grid(int lev1 = 1, int lev2 = 1);
		void nextBlock();
		void moveBlock(std::string dir);
		void rotateBlock(bool clock);
		void dropBlock();
	friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
