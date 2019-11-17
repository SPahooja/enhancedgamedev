#ifndef PIECE_H
#define PIECE_H
#include "cell.h"
#include <iostream>
#include <string>
#include <vector>

class Cell;

class Piece {
	protected:
		char disp;
		int valid;
		std::vector<Cell*> ptr;
	public:
		void movepos(std::string dir);
		void rowdel();
		void drop();
		virtual void rotate(bool cl) = 0;
		virtual ~Piece() = 0;
};

#endif
