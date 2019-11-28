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
	bool random;
	std::string file;
	int pos;
	int len;
	public:
		LevelFour(int s=0, std::string file="");
		Piece* nextPiece(std::vector<std::vector<std::unique_ptr<Cell>>> &t) override;
};

#endif
