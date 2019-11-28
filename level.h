#ifndef LEVEL_H
#define LEVEL_H
#include "piece.h"
#include <iostream>
#include <vector>
#include <memory>

class Piece;
class Cell;
class Level {
	public:
		virtual Piece* nextPiece(std::vector<std::vector<std::unique_ptr<Cell>>> &t) = 0;
};

#endif
