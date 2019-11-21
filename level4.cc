#include "level4.h"
#include <vector>
#include <cstdlib>
using namespace std;

LevelFour::LevelFour(int s): seed{s} {}

Piece* LevelFour::nextPiece(vector<vector<Cell*>> &t) {
	srand(this->seed);
	int pos = rand()%9+1;
    Piece *pc = nullptr;
    if ((pos==1)||(pos==2)) {
        pc = new PieceZ(t);
    }
    else if ((pos==3)||(pos==4)) {
        pc = new PieceS(t);
    }
    else if (pos==5) {
        pc = new PieceI(t);
    }
    else if (pos==6) {
        pc = new PieceO(t);
    }
    else if (pos==7) {
        pc = new PieceT(t);
    }
    else if (pos==8) {
        pc = new PieceJ(t);
    }
    else if (pos==9) {
    }
    return pc;
}