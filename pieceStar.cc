#include "pieceStar.h"
#include "piece.h"
#include "cell.h"
#include <stdexcept>
#include <vector>
using namespace std;

PieceStar::PieceStar(vector<vector<Cell*>> &t) {
	this->disp = '*';
	int i=2;
	while ((i<17)&&(!t[i+1][5]->getbl())) {
	       cout << i << endl;
       	       ++i; }
	(this->ptr).push_back(t[i][5]);
	for (int j=0; j<3; j++) {
		Cell *temp = nullptr;
		(this->ptr).push_back(temp);
	}
	t[i][5]->setdisp(this->disp);
	t[i][5]->setbl(true);
}

void PieceStar::transferPiece(std::vector<std::vector<Cell*>> &src, std::vector<std::vector<Cell*>> &des) {}

PieceStar::~PieceStar() {}

void PieceStar::rotate(bool cl) {}
