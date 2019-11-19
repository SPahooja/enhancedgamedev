#ifndef LEVEL_H
#define LEVEL_H
#include "piece.h"
#include <iostream>
#include <vector>

class Piece;
class Cell;
class Level {
	public:
		virtual Piece* nextPiece(int p, std::vector<std::vector<Cell*>> &t) = 0;
};

#endif
