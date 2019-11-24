#ifndef LEVEL3_H
#define LEVEL3_H
#include "level.h"
#include "pieceI.h"
#include "pieceZ.h"
#include "pieceS.h"
#include "pieceT.h"
#include "pieceO.h"
#include "pieceJ.h"
#include "pieceL.h"
#include <fstream>
#include <iostream>
#include <string>

class Piece;
class Cell;

class LevelThree: public Level {
	int seed;
	bool random;
        std::string file;
        int pos;
        int len;
	public:
		LevelThree(int s=0, std::string file="");
		Piece* nextPiece(std::vector<std::vector<Cell*>> &t) override;
};

#endif
