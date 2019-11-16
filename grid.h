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
	public:
		Grid();


}
