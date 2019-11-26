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
		void rowdel(int j);
		void drop();
		virtual void transferPiece(std::vector<std::vector<Cell*>> &src, std::vector<std::vector<Cell*>> &des) = 0;
		virtual void rotate(bool cl) = 0;
		virtual ~Piece() = 0;
};

#endif
