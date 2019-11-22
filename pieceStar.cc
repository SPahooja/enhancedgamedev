#include "pieceStar.h"
#include "piece.h"
#include "cell.h"
#include <stdexcept>
#include <vector>
using namespace std;

PieceStar::PieceStar(vector<vector<Cell*>> &t) {
	this->valid = 1;
	this->disp = '*';
	(this->ptr).push_back(t[3][5]);
	t[3][5]->setdisp(this->disp);
	t[3][5]->setbl(true);
}

void PieceStar::transferPiece(std::vector<std::vector<Cell*>> &src, std::vector<std::vector<Cell*>> &des) {}

PieceStar::~PieceStar() {}

void PieceStar::rotate(bool cl) {}