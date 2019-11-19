#include "pieceS.h"
#include "piece.h"
#include "cell.h"
#include <vector>

using namespace std;

PieceS::PieceS(vector<vector<Cell*>> &t) {              // Creating at top-left
    this->valid = 4;
    this->disp = 'S';
    for (int i = 2; i >= 1; --i) {
        (this->ptr).push_back(t[3][i]);
        t[3][i]->setdisp('S');
        t[3][i]->setbl(true);
    }
    for (int i = 1; i >= 0; --i) {
        (this->ptr).push_back(t[4][i]);
        t[4][i]->setdisp('S');
        t[4][i]->setbl(true);
    }
}

PieceS::~PieceS() {}

void PieceS::rotate(bool cl) {
    bool vert;
    int row1 = (this->ptr)[0]->getrow();
    int col1 = (this->ptr)[0]->getcol();
    int row4 = (this->ptr)[3]->getrow();
    int col4 = (this->ptr)[3]->getcol();
    if ((row1 - row4 == 1) || (row1 - row4 == -1)) {            // Checking orientation (0123 or 3210)
        vert = false;
        if ((row1 < 1) || (row1 > 16)) {
            return;
        }
        
    } else if ((row1 - row4 == 2) || (row1 - row4 == -2)) {
        vert = true;
        if ((col1 < 1) || (col1 > 9)) {
            return;
        }
        
    }

    Cell *temp3 = (this->ptr)[3];
    Cell *temp1 = (this->ptr)[1];
    Cell *temp0 = (this->ptr)[0];
    
    for (int i = 0; i <= 1; ++i) {              // Checking for empty cells
        if (!vert) {
            temp3 = temp3->getUp();
	    if (temp3->getbl()) {
		    return;
	    }
        } else {
            if (i == 0) {
                temp0 = temp0->getLeft();
                if (temp0->getbl())
                    return;
            } else {
                temp1 = temp1->getRight();
                if (temp1->getbl())
                    return;
            }
        }
    }

    if (vert) {
        (this->ptr)[3]->setdisp(' ');
        (this->ptr)[3]->setbl(false);
        (this->ptr)[3] = (this->ptr)[3]->getDown();
        (this->ptr)[3] = (this->ptr)[3]->getDown();
        (this->ptr)[3]->setdisp(this->disp);
        (this->ptr)[3]->setbl(true);
        (this->ptr)[0]->setdisp(' ');
        (this->ptr)[0]->setbl(false);
        (this->ptr)[0] = (this->ptr)[0]->getUp();
        (this->ptr)[0] = (this->ptr)[0]->getRight();
        (this->ptr)[0]->setdisp(this->disp);
        (this->ptr)[0]->setbl(true);
        (this->ptr)[2]->setdisp(' ');
        (this->ptr)[2]->setbl(false);
        (this->ptr)[2] = (this->ptr)[2]->getDown();
        (this->ptr)[2] = (this->ptr)[2]->getRight();
        (this->ptr)[2]->setdisp(this->disp);
        (this->ptr)[2]->setbl(true);
    } else {
        (this->ptr)[3]->setdisp(' ');
        (this->ptr)[3]->setbl(false);
        (this->ptr)[3] = (this->ptr)[3]->getUp();
        (this->ptr)[3] = (this->ptr)[3]->getUp();
        (this->ptr)[3]->setdisp(this->disp);
        (this->ptr)[3]->setbl(true);
        (this->ptr)[2]->setdisp(' ');
        (this->ptr)[2]->setbl(false);
        (this->ptr)[2] = (this->ptr)[2]->getLeft();
        (this->ptr)[2] = (this->ptr)[2]->getUp();
        (this->ptr)[2]->setdisp(this->disp);
        (this->ptr)[2]->setbl(true);
        (this->ptr)[0]->setdisp(' ');
        (this->ptr)[0]->setbl(false);
        (this->ptr)[0] = (this->ptr)[0]->getDown();
        (this->ptr)[0] = (this->ptr)[0]->getLeft();
        (this->ptr)[0]->setdisp(this->disp);
        (this->ptr)[0]->setbl(true);
    }
    
}
