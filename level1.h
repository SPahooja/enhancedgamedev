#ifndef LEVEL1_H
#define LEVEL1_H
#include "level.h"
#include "pieceI.h"
#include "pieceZ.h"
#include "pieceS.h"
#include "pieceT.h"
#include "pieceO.h"
#include "pieceJ.h"
#include "pieceL.h"
#include <fstream>

class Piece;
class Cell;

class LevelOne: public Level {
	int seed;
	public:
		LevelOne(int s=0);
		Piece* nextPiece(std::vector<std::vector<Cell*>> &t) override;
};

#endif
