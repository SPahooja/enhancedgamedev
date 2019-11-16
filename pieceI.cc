#include "pieceI.h"
#include "piece.h"
#include "cell.h"
#include <vector>
using namespace std;

PieceI::PieceI(vector<vector<Cell*>> &t) {
	this->valid = 4;
	this->disp = 'I';
	for (int i=0; i < 4; i++) {
		(this->ptr).push_back(t[3][i]);
		t[3][i]->setdisp('I');
		t[3][i]->setbl(true);
	}
}

PieceI::~PieceI() {}

void PieceI::rotate(bool cl) {}
