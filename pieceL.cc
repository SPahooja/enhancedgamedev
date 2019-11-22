#include "pieceL.h"
#include "piece.h"
#include "cell.h"
#include <vector>
using namespace std;

PieceL::PieceL(vector<vector<Cell*>> &t) {
	this->valid = 4;
    	this->disp = 'L';
	(this->ptr).push_back(t[2][2]);
	(this->ptr).push_back(t[3][2]);
	(this->ptr).push_back(t[3][1]);
	(this->ptr).push_back(t[3][0]);
	for (int i=0; i < 4; i++) {
		ptr[i]->setdisp('L');
		ptr[i]->setbl(true);
	}
}

void PieceL::transferPiece(std::vector<std::vector<Cell*>> &src, std::vector<std::vector<Cell*>> &des){
	for (int i=0; i<4; i++) {
		ptr[i]->setdisp(' ');
		ptr[i]->setbl(false);
	}
	ptr[0] = des[2][2];
	ptr[1] = des[3][2];
	ptr[2] = des[3][1];
	ptr[3] = des[3][0];
	for (int i=0; i<4; i++) {
		if (ptr[i]->getbl()) { throw invalid_argument("Game Over"); }
		ptr[i]->setdisp(this->disp);
		ptr[i]->setbl(true);
	}
}

PieceL::~PieceL() {}

void PieceL::rotate(bool cl){
	bool vert;
	bool tipup = false;
	vector<Cell*> temp = (this->ptr);
	int row0 = (this->ptr)[0]->getrow();
	int col0 = (this->ptr)[0]->getcol();
	int row1 = (this->ptr)[1]->getrow();
	int col1 = (this->ptr)[1]->getcol();
    	int row2 = (this->ptr)[2]->getrow();
	int col2 = (this->ptr)[2]->getcol();
	int row3 = (this->ptr)[3]->getrow();
	int col3 = (this->ptr)[3]->getcol();

    if(row3 == row1){
        vert = false;
        if(row0 < row1){
            tipup = true;
        }
        else{
            tipup = false;
        }
    }
    else{
        vert = true;
        if(col0 < col3){
            tipup = true;
        }
        else{
            tipup = false;
        }
    }

    if((!vert) && tipup && cl){
        Cell *temp = (this->ptr)[3];
        for(int i = 0; i < 2; ++i){
            temp = temp->getUp();
            if((temp==nullptr)||(temp->getbl())){return;}
        }
        for(int i = 0; i <= 3; ++i){
        (this->ptr)[i]->setdisp(' ');
		(this->ptr)[i]->setbl(false);
    }
        (this->ptr)[0] = (this->ptr)[2];
        (this->ptr)[1] = (this->ptr)[3];
    	(this->ptr)[2] = ((this->ptr)[1])->getUp();
        (this->ptr)[3] = ((this->ptr)[2])->getUp();
    }

    else if(vert && (!tipup) && cl){
       Cell *temp = (this->ptr)[2];
        for(int i = 0; i < 2; ++i){
            temp = temp->getRight();
            if((temp==nullptr)||(temp->getbl())){return;}
        } 
        for(int i = 0; i <= 3; ++i){
        (this->ptr)[i]->setdisp(' ');
		(this->ptr)[i]->setbl(false);
    }
        (this->ptr)[0] = (this->ptr)[1];
        (this->ptr)[1] = (this->ptr)[2];
        (this->ptr)[2] = ((this->ptr)[1])->getRight();
        (this->ptr)[3] = ((this->ptr)[2])->getRight();
    }

    else if((!vert) && (!tipup) && cl){
        Cell *temp = ((this->ptr)[2])->getUp();
		if((temp==nullptr)||(temp->getbl())){return;}
		temp = temp->getLeft();
		if((temp==nullptr)||(temp->getbl())){return;}
		temp = ((this->ptr)[2])->getDown();
		if((temp==nullptr)||(temp->getbl())){return;}
        for(int i = 0; i <= 3; ++i){
        (this->ptr)[i]->setdisp(' ');
		(this->ptr)[i]->setbl(false);
    }
        (this->ptr)[0] = (((this->ptr)[2])->getUp())->getLeft();
		(this->ptr)[1] = ((this->ptr)[2])->getUp();
		(this->ptr)[3] = ((this->ptr)[2])->getDown();
    }

    else if(vert && tipup && cl){
        Cell *temp = ((this->ptr)[3])->getRight();
		if((temp==nullptr)||(temp->getbl())){return;}
		temp = temp->getUp();
		if((temp==nullptr)||(temp->getbl())){return;}
		temp = ((this->ptr)[3])->getLeft();
		if((temp==nullptr)||(temp->getbl())){return;}
        for(int i = 0; i <= 3; ++i){
        (this->ptr)[i]->setdisp(' ');
		(this->ptr)[i]->setbl(false);
    }
        (this->ptr)[0] = (((this->ptr)[3])->getRight())->getUp();
		(this->ptr)[1] = ((this->ptr)[3])->getRight();
        (this->ptr)[2] = (this->ptr)[3];
        (this->ptr)[3] = ((this->ptr)[2])->getLeft();
    }

    else if((!vert) && tipup && (!cl)){
      Cell *temp = (this->ptr)[2];
      for(int i = 0; i < 2; ++i){
		temp = temp->getUp();
		if((temp==nullptr)||(temp->getbl())){
			return;
            }
        }
		temp = temp->getLeft();
		if((temp==nullptr)||(temp->getbl())){return;}
        for(int i = 0; i <= 3; ++i){
        (this->ptr)[i]->setdisp(' ');
		(this->ptr)[i]->setbl(false);
    }
        (this->ptr)[0] = ((((this->ptr)[2])->getUp())->getUp())->getLeft();
        (this->ptr)[1] = ((this->ptr)[0])->getRight();
        (this->ptr)[2] = ((this->ptr)[1])->getDown();
        (this->ptr)[3] = ((this->ptr)[2])->getDown();
    }

    if(vert && tipup && (!cl)){
        Cell *temp = ((this->ptr)[2])->getLeft();
		if((temp==nullptr)||(temp->getbl())){return;}
		temp = temp->getDown();
		if((temp==nullptr)||(temp->getbl())){return;}
		temp = ((this->ptr)[2])->getRight();
		if((temp==nullptr)||(temp->getbl())){return;}
        for(int i = 0; i <= 3; ++i){
        (this->ptr)[i]->setdisp(' ');
		(this->ptr)[i]->setbl(false);
    }
        (this->ptr)[0] = (((this->ptr)[2])->getLeft())->getDown();
		(this->ptr)[1] = ((this->ptr)[2])->getLeft();
		(this->ptr)[3] = ((this->ptr)[2])->getRight();
    }

    if((!vert) && (!tipup) && (!cl)){
       Cell *temp = ((this->ptr)[1])->getUp();
		if((temp==nullptr)||(temp->getbl())){return;}
		temp = ((this->ptr)[0])->getRight();
		if((temp==nullptr)||(temp->getbl())){return;}
        for(int i = 0; i <= 3; ++i){
        (this->ptr)[i]->setdisp(' ');
		(this->ptr)[i]->setbl(false);
    }
        (this->ptr)[0] = ((this->ptr)[0])->getRight();
        (this->ptr)[1] = ((this->ptr)[1])->getDown();
        (this->ptr)[2] = ((this->ptr)[1])->getUp();
        (this->ptr)[3] = ((this->ptr)[2])->getUp();
    }

    if(vert && (!tipup) && (!cl)){
        Cell *temp = ((this->ptr)[0])->getRight();
		if((temp==nullptr)||(temp->getbl())){return;}
		temp = temp->getUp();
		if((temp==nullptr)||(temp->getbl())){return;}
        for(int i = 0; i <= 3; ++i){
        (this->ptr)[i]->setdisp(' ');
		(this->ptr)[i]->setbl(false);
    }
        (this->ptr)[3] = (this->ptr)[1];
        (this->ptr)[2] = (this->ptr)[0];
        (this->ptr)[1] = ((this->ptr)[2])->getRight();
        (this->ptr)[0] = ((this->ptr)[1])->getUp();
    }

    for(int i = 0; i <= 3; ++i){
			(this->ptr)[i]->setdisp(this->disp);
			(this->ptr)[i]->setbl(true);
		}
}

