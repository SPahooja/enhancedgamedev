#ifndef LEVEL0_H
#define LEVEL0_H
#include "level.h"
#include <fstream>

class Piece;
class Cell;

class LevelZero: public Level {
	int pos;
	int len;
	std::string fl;
	public:
		LevelZero(std::string s);
		Piece* nextPiece(std::vector<std::vector<Cell*>> &t) override;
};

#endif
