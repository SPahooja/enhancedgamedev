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

void PieceO::transferPiece(std::vector<std::vector<Cell*>> &src, std::vector<std::vector<Cell*>> &des) {
	for (int i=0; i<4; i++) {
		ptr[i]->setdisp(' ');
		ptr[i]->setbl(true);
	}
	ptr[0] = des[2][0];
	ptr[1] = des[2][1];
	ptr[2] = des[3][0];
	ptr[3] = des[3][1];
	for (int i=0; i<4; i++) {
		if (ptr[i]->getbl()) { throw invalid_argument("Game Over"); }
		ptr[i]->setdisp('O');
		ptr[i]->setbl(true);
	}
}

PieceO::~PieceO() {}

void PieceO::rotate(bool cl) {}
