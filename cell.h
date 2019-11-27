#ifndef CELL_H
#define CELL_H
#include "subject.h"
#include "state.h"
#include <iostream>

class Cell: public Subject {
	int row, col;
	Position p;
	bool isoccup;
	char disp;
	Cell *left;
	Cell *right;
	Cell *up;
	Cell *down;
	public:
		Cell(int r, int c, Position p);
		Cell *getLeft() const;
		Cell *getRight() const;
		Cell *getUp() const;
		Cell *getDown() const;
		void setDir(Cell* l, Cell* r, Cell* u, Cell *d);
		char getdisp() const;
		void setdisp(char c);
		bool getbl() const;
		void setbl(bool b);
		int getrow() const;
		int getcol() const;
		void makeblind();
		void removeblind();
};

#endif
