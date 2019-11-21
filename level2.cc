#include "level2.h"
#include <vector>
#include <cstdlib>
using namespace std;

LevelTwo::LevelTwo(int s): seed{s} {}

Piece* LevelTwo::nextPiece(vector<vector<Cell*>> &t) {
	srand(this->seed);
	int pos = rand()%7+1;
	Piece *pc = nullptr;
	if (pos==1) {
		pc = new PieceZ(t);
	}
	else if (pos==2) {
		pc = new PieceS(t);
	}
	else if (pos==3) {
		pc = new PieceI(t);
	}
	else if (pos==4) {
		pc = new PieceO(t);
	}
	else if (pos==5) {
		pc = new PieceT(t);
	}
	else if (pos==6) {
	}
	else if (pos==7) {
	}
	return pc;
}
