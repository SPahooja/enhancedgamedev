#include "pieceO.h"
#include "piece.h"
#include "cell.h"
#include <vector>
using namespace std;

PieceO::PieceO(vector<vector<unique_ptr<Cell>>> &t) {
	this->disp = 'O';
	(this->ptr).push_back(t[2][0].get());
	(this->ptr).push_back(t[2][1].get());
	(this->ptr).push_back(t[3][0].get());
	(this->ptr).push_back(t[3][1].get());
	for (int i=0; i < 4; i++) {
		ptr[i]->setdisp('O');
		ptr[i]->setbl(true);
	}
}

void PieceO::transferPiece(std::vector<std::vector<unique_ptr<Cell>>> &src, std::vector<std::vector<unique_ptr<Cell>>> &des) {
	for (int i=0; i<4; i++) {
		ptr[i]->setdisp(' ');
		ptr[i]->setbl(true);
	}
	ptr[0] = des[2][0].get();
	ptr[1] = des[2][1].get();
	ptr[2] = des[3][0].get();
	ptr[3] = des[3][1].get();
	for (int i=0; i<4; i++) {
		if (ptr[i]->getbl()) { throw invalid_argument("Game Over"); }
		ptr[i]->setdisp('O');
		ptr[i]->setbl(true);
	}
}

PieceO::~PieceO() {}

void PieceO::rotate(bool cl) {}
