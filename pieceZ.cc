#include "pieceZ.h"
#include "piece.h"
#include "cell.h"
#include <vector>

using namespace std;

PieceZ::PieceZ(vector<vector<Cell*>> &t) {              // Creating at top-left
    this->valid = 4;
    this->disp = 'Z';
    for (int i = 0; i <= 1; ++i) {
        (this->ptr).push_back(t[3][i]);
        t[3][i]->setdisp('Z');
        t[3][i]->setbl(true);
    }
    for (int i = 1; i <= 2; ++i) {
        (this->ptr).push_back(t[4][i]);
        t[4][i]->setdisp('Z');
        t[4][i]->setbl(true);
    }
}

PieceZ::~PieceZ() {}

void PieceZ::transferPiece(std::vector<std::vector<Cell*>> &src, std::vector<std::vector<Cell*>> &des) {
	for (int i=0; i<4; i++) {
		ptr[i]->setdisp(' ');
		ptr[i]->setbl(false);
	}
	ptr[0] = des[3][0];
	ptr[1] = des[3][1];
	ptr[2] = des[4][1];
	ptr[3] = des[4][2];
	for (int i=0; i<4; i++) {
		ptr[i]->setdisp('Z');
		ptr[i]->setbl(true);
	}
}

void PieceZ::rotate(bool cl) {
    bool vert;
    int row1 = (this->ptr)[0]->getrow();
    int col1 = (this->ptr)[0]->getcol();
    int row4 = (this->ptr)[3]->getrow();
    int col4 = (this->ptr)[3]->getcol();
    if ((row1 - row4 == 1) || (row1 - row4 == -1)) {            // Checking orientation (0123 or 3210)
        vert = false;
        if ((row1 < 1) || (row4 > 16)) {
            return;
        }
    } else if ((row1 - row4 == 2) || (row1 - row4 == -2)) {
        vert = true;
        if ((col1 > 9) || (col4 < 1)) {
            return;
        }
    }
    Cell *temp0 = (this->ptr)[0];
    Cell *temp1 = (this->ptr)[1];
    Cell *temp2 = (this->ptr)[2];
    Cell *temp3 = (this->ptr)[3];
    for (int i = 0; i <= 1; ++i) {              // Checking for empty cells
        if (vert) {
            temp3 = temp3->getRight();
	    if (temp3->getbl()) {
		    return;
	    }
        } else {
            if (i == 0) {
                temp0 = temp0->getDown();
                if (temp0->getbl())
                    return;
            } else {
                temp1 = temp1->getUp();
                if (temp1->getbl())
                    return;
            }
        }
    }
    if (vert) {
        (this->ptr)[3]->setdisp(' ');
        (this->ptr)[3]->setbl(false);
        (this->ptr)[3] = (this->ptr)[3]->getRight();
        (this->ptr)[3] = (this->ptr)[3]->getRight();
        (this->ptr)[3]->setdisp(this->disp);
        (this->ptr)[3]->setbl(true);
        (this->ptr)[2]->setdisp(' ');
        (this->ptr)[2]->setbl(false);
        (this->ptr)[2] = (this->ptr)[2]->getDown();
        (this->ptr)[2] = (this->ptr)[2]->getRight();
        (this->ptr)[2]->setdisp(this->disp);
        (this->ptr)[2]->setbl(true);
        (this->ptr)[0]->setdisp(' ');
        (this->ptr)[0]->setbl(false);
        (this->ptr)[0] = (this->ptr)[0]->getDown();
        (this->ptr)[0] = (this->ptr)[0]->getLeft();
        (this->ptr)[0]->setdisp(this->disp);
        (this->ptr)[0]->setbl(true);
    } else {
        (this->ptr)[3]->setdisp(' ');
        (this->ptr)[3]->setbl(false);
        (this->ptr)[3] = (this->ptr)[3]->getLeft();
        (this->ptr)[3] = (this->ptr)[3]->getLeft();
        (this->ptr)[3]->setdisp(this->disp);
        (this->ptr)[3]->setbl(true);
        (this->ptr)[0]->setdisp(' ');
        (this->ptr)[0]->setbl(false);
        (this->ptr)[0] = (this->ptr)[0]->getRight();
        (this->ptr)[0] = (this->ptr)[0]->getUp();
        (this->ptr)[0]->setdisp(this->disp);
        (this->ptr)[0]->setbl(true);
        (this->ptr)[2]->setdisp(' ');
        (this->ptr)[2]->setbl(false);
        (this->ptr)[2] = (this->ptr)[2]->getLeft();
        (this->ptr)[2] = (this->ptr)[2]->getUp();
        (this->ptr)[2]->setdisp(this->disp);
        (this->ptr)[2]->setbl(true);
    }
}
