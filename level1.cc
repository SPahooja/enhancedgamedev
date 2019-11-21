#include "level1.h"
#include <vector>
#include <cstdlib>
using namespace std;

LevelOne::LevelOne(int s): seed{s} {
	srand(s);
}

Piece* LevelOne::nextPiece(vector<vector<Cell*>> &t) {
	int pos = rand()%12+1;
	Piece *pc = nullptr;
	if (pos==1) {
		pc = new PieceZ(t);
	}
	else if (pos==2) {
		pc = new PieceS(t);
	}
	else if ((pos==3)||(pos==4)) {
		pc = new PieceI(t);
	}
	else if ((pos==5)||(pos==6)) {
		pc = new PieceO(t);
	}
	else if ((pos==7)||(pos==8)) {
		pc = new PieceT(t);
	}
	else if ((pos==9)||(pos==10)) {
		pc = new PieceJ(t);
	}
	else if ((pos==11)||(pos==12)) {
	}
	return pc;
}
