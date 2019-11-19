#ifndef LEVEL0_H
#define LEVEL0_H
#include "level.h"
#include <fstream>

class Piece;
class Cell;

class LevelZero: public Level {
	int pos1;
	int len1;
	int pos2;
	int len2;
	public:
		LevelZero();
		Piece* nextPiece(int p, std::vector<std::vector<Cell*>> &t) override;
};

#endif
