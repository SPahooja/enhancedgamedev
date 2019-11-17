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

void PieceI::rotate(bool cl) {
	int anchor;
	bool vert;
	int row1 = (this->ptr)[0]->getrow();
	int col1 = (this->ptr)[0]->getcol();
	int row4 = (this->ptr)[3]->getrow();
	int col4 = (this->ptr)[3]->getcol();
	if (row1==row4) {
		vert = false;
		if (col1 < col4) {
			anchor = 0;
		}
		else {
			anchor = 3;
		}
		if (((cl)&&(row1>=15))||((!cl)&&(row1<=2))) {
			return;
		}
	}
	else if (col1==col4) {
		vert = true;
		if (row1 > row4) {
			anchor = 0;
		}
		else {
			anchor = 3;
		}
		if (((!cl)&&(col1<=2))||((cl)&&(col1>=15))) {
			return;
		}
	}
	if (anchor==0) {
		for (int i=1; i<4; i++) {
			(this->ptr)[i]->setdisp(' ');
			(this->ptr)[i]->setbl(false);
			if (vert) {
				(this->ptr)[i] = cl?(this->ptr)[i-1]->getRight():(this->ptr)[i-1]->getLeft();
			}
			else {
				(this->ptr)[i] = cl?(this->ptr)[i-1]->getDown():(this->ptr)[i-1]->getUp();
			}
			(this->ptr)[i]->setdisp(this->disp);
			(this->ptr)[i]->setbl(true);
		}
	}
	if (anchor==3) {
                for (int i=2; i>=0; i--) {
			(this->ptr)[i]->setdisp(' ');
                        (this->ptr)[i]->setbl(false);
			if (vert) {
				(this->ptr)[i] = cl?(this->ptr)[i+1]->getRight():(this->ptr)[i+1]->getLeft();
			}
			else {
				(this->ptr)[i] = cl?(this->ptr)[i+1]->getDown():(this->ptr)[i+1]->getUp();
			}
			(this->ptr)[i]->setdisp(this->disp);
			(this->ptr)[i]->setbl(true);
                }
        }
}
