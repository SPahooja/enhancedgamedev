#ifndef PIECE_H
#define PIECE_H
#include "cell.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Cell;

class Piece {
	protected:
		char disp;
		std::vector<Cell*> ptr;
	public:
		void movepos(std::string dir, int c);
		void rowdel(int j);
		void drop();
		virtual void transferPiece(std::vector<std::vector<std::unique_ptr<Cell>>> &src, std::vector<std::vector<std::unique_ptr<Cell>>> &des) = 0;
		virtual void rotate(bool cl) = 0;
		virtual ~Piece() = 0;
};

#endif
