#include "pieceO.h"
#include "piece.h"
#include "cell.h"
#include <vector>
using namespace std;

PieceO::PieceO(vector<vector<Cell*>> &t) {
	this->valid = 4;
	this->disp = 'O';
	(this->ptr).push_back(t[2][0]);
	(this->ptr).push_back(t[2][1]);
	(this->ptr).push_back(t[3][0]);
	(this->ptr).push_back(t[3][1]);
	for (int i=0; i < 4; i++) {
		ptr[i]->setdisp('O');
		ptr[i]->setbl(true);
	}
}

PieceO::~PieceO() {}

void PieceO::rotate(bool cl) {}
