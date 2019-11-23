#ifndef LEVEL4_H
#define LEVEL4_H
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

class LevelFour: public Level {
	int seed;
	public:
		LevelFour(int s=0);
		Piece* nextPiece(std::vector<std::vector<Cell*>> &t) override;
};

#endif
