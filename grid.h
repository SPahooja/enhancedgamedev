#ifndef GRID_H
#define GRID_H
#include "cell.h"
#include <iostream>
#include <fstream>
#include <vector>

class Cell;
class Piece;
class Level;
class GraphicDisplay {};

class Grid {
	std::vector<std::vector<Cell*>> map1;
	std::vector<Piece*> move1;
	Level *lp1;
	int curscore1;
	int lev1;
	Piece* nxtpc1;
	std::vector<std::vector<Cell*>> nxtmap1;
	int uns1;
	std::vector<std::vector<Cell*>> map2;
	std::vector<Piece*> move2;
	Level *lp2;
	int curscore2;
	int lev2;
	Piece* nxtpc2;
	std::vector<std::vector<Cell*>> nxtmap2;
	int uns2;
	GraphicDisplay *gd;
	public:
		Grid(int l1=0, int l2=0);
		void nextBlock(int p);
		void moveBlock(int p, std::string dir);
		void rotateBlock(int p, bool clock);
		void dropBlock(int p);
		void chngLevel(int p, bool up);
		int getLevel(int p);
		int getWinner();
		~Grid();
	friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
