#ifndef CELL_H
#define CELL_H
#include <iostream>

class Cell {
	int row, col;
	bool isoccup;
	char disp;
	Cell *left;
	Cell *right;
	Cell *up;
	Cell *down;
	public:
		Cell(int r, int c);
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
};

#endif
