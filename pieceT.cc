#include "pieceT.h"
#include "piece.h"
#include "cell.h"
#include <vector>
using namespace std;

PieceT::PieceT(vector<vector<Cell*>> &t) {
        this->valid = 4;
        this->disp = 'T';
        for (int i=0; i < 3; i++) {
                (this->ptr).push_back(t[2][i]);
                t[2][i]->setdisp('T');
                t[2][i]->setbl(true);
        }
	(this->ptr).push_back(t[3][1]);
	t[3][1]->setdisp('T');
	t[3][1]->setbl(true);
}

PieceT::~PieceT() {}

void PieceT::transferPiece(std::vector<std::vector<Cell*>> &src, std::vector<std::vector<Cell*>> &des) {
	for (int i=0; i<4; i++) {
		(this->ptr)[i]->setdisp(' ');
		(this->ptr)[i]->setbl(false);
	}
	for (int i=0; i < 3; i++) {
		(this->ptr)[i] = des[2][i];
		if (ptr[i]->getbl()) { throw invalid_argument("Game Over"); }
		(this->ptr)[i]->setdisp('T');
		(this->ptr)[i]->setbl(true);
	}
	(this->ptr)[3] = des[3][1];
	if (ptr[3]->getbl()) { throw invalid_argument("Game Over"); }
	(this->ptr)[3]->setdisp('T');
	(this->ptr)[3]->setbl(true);
}

void PieceT::rotate(bool cl) {
	int anchor;
	bool vert;
	bool fourthup = false;
	vector<Cell*> temp = (this->ptr);
	int row1 = (this->ptr)[0]->getrow();
	int col1 = (this->ptr)[0]->getcol();
	int row3 = (this->ptr)[2]->getrow();
	int col3 = (this->ptr)[2]->getcol();
	int row4 = (this->ptr)[3]->getrow();
	int col4 = (this->ptr)[3]->getcol();
	if (row1==row3) {
                vert = false;
                if (col1 < col3) {
                        anchor = 0;
                }
                else {
                        anchor = 2;
                }
                if (((cl)&&(row1>=16))||((!cl)&&(row1<=1))) {
                        return;
                }
		if (row4 < row1) {
			fourthup = true;
		}
        }
        else if (col1==col3) {
                vert = true;
                if (row1 > row3) {
                        anchor = 0;
                }
                else {
                        anchor = 2;
                }
                if (((!cl)&&(col1<=1))||((cl)&&(col1>=9))) {
                        return;
                }
		if (col4 > col1) {
			fourthup = true;
		}
        }
        if (anchor==0) {
                for (int i=1; i<3; i++) {
                        if (vert) {
                                temp[i] = cl?temp[i-1]->getRight():temp[i-1]->getLeft();
                        }
                        else {
                                temp[i] = cl?temp[i-1]->getDown():temp[i-1]->getUp();
                        }
			if ((temp[i]==nullptr)||(temp[i]->getbl())) {
				return;
			}
                }
        }
	if (anchor==2) {
                for (int i=1; i>=0; i--) {
                        if (vert) {
                                temp[i] = cl?temp[i+1]->getRight():temp[i+1]->getLeft();
                        }
                        else {
                                temp[i] = cl?temp[i+1]->getDown():temp[i+1]->getUp();
                        }
                        if ((temp[i]==nullptr)||(temp[i]->getbl())) {
				return;
			}
                }
        }
	if (vert) {
		if (cl) {
			temp[3] = fourthup?temp[1]->getDown():temp[1]->getUp();
		}
		else {
			temp[3] = fourthup?temp[1]->getUp():temp[1]->getDown();
		}
	}
	else {
		if (cl) {
			temp[3] = fourthup?temp[1]->getRight():temp[1]->getLeft();
		}
		else {
			temp[3] = fourthup?temp[1]->getLeft():temp[1]->getRight();
		}
	}
	if ((temp[3]==nullptr)||(temp[3]->getbl())) {
		return;
	}
	for (int i=0; i < 4; i++) {
		(this->ptr)[i]->setdisp(' ');
		(this->ptr)[i]->setbl(false);
	}
	for (int i=0; i < 4; i++) {
		(this->ptr)[i] = temp[i];
		(this->ptr)[i]->setdisp(this->disp);
		(this->ptr)[i]->setbl(true);
	}
}

