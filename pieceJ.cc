#include "pieceJ.h"
#include "piece.h"
#include "cell.h"
#include <vector>
using namespace std;

PieceJ::PieceJ(vector<vector<Cell*>> &t) {
	this->valid = 4;
    this->disp = 'J';
	(this->ptr).push_back(t[2][0]);
	(this->ptr).push_back(t[3][0]);
	(this->ptr).push_back(t[3][1]);
	(this->ptr).push_back(t[3][2]);
	for (int i=0; i < 4; i++) {
		ptr[i]->setdisp('J');
		ptr[i]->setbl(true);
	}
}

PieceJ::~PieceJ() {}

void PieceJ::rotate(bool cl){
	bool vert;
	bool tipup = false;
	vector<Cell*> temp = (this->ptr);
	int row1 = (this->ptr)[0]->getrow();
	int col1 = (this->ptr)[0]->getcol();
	int row2 = (this->ptr)[1]->getrow();
	//int col2 = (this->ptr)[1]->getcol();
	int row4 = (this->ptr)[3]->getrow();
	int col4 = (this->ptr)[3]->getcol();

	if(row2 == row4){
		vert = false;
		if(col1 < col4){
			tipup = true;
		}
		else{
			tipup = false;
		}
	}
	else{
	       vert = true;
	       if(row1 < row4){
		       tipup = true;
	       }
	       else tipup = false;
	}

	if((!vert) && tipup && cl){
		Cell *temp = (this->ptr)[0];
		for(int i = 0; i < 2; ++i){
			temp = temp->getUp();
			if((temp==nullptr)||(temp->getbl())){
				return;
			}
		}
		temp = temp->getRight();
		if((temp==nullptr)||(temp->getbl())){return;}

		(this->ptr)[2]->setdisp(' ');
		(this->ptr)[2]->setbl(false);
		(this->ptr)[3]->setdisp(' ');
		(this->ptr)[3]->setbl(false);
		(this->ptr)[0] = ((this->ptr)[0]->getUp())->getRight();
		(this->ptr)[0]->setdisp(this->disp);
		(this->ptr)[0]->setbl(true);
		(this->ptr)[1] = ((this->ptr)[1]->getUp())->getUp();
		(this->ptr)[1]->setdisp(this->disp);
		(this->ptr)[1]->setbl(true);
		(this->ptr)[2] = (this->ptr)[1]->getDown();
		(this->ptr)[3] = (this->ptr)[2]->getDown();
	}

	else if(vert && tipup && cl){
		Cell *temp = (this->ptr)[2];
		for(int i = 0; i < 2; ++i){
			temp = temp->getRight();
			if((temp==nullptr)||(temp->getbl())){
				return;
			}
		}
		temp = temp->getRight();
		if((temp==nullptr)||(temp->getbl())){return;}

		(this->ptr)[0]->setdisp(' ');
		(this->ptr)[0]->setbl(false);
		(this->ptr)[1]->setdisp(' ');
		(this->ptr)[1]->setbl(false);
		(this->ptr)[3]->setdisp(' ');
		(this->ptr)[3]->setbl(false);
		(this->ptr)[0] = (((this->ptr)[2]->getRight())->getRight())->getDown();
		(this->ptr)[1] = ((this->ptr)[2]->getRight())->getRight();
		(this->ptr)[2] = (this->ptr)[2]->getRight();
		(this->ptr)[3] = (this->ptr)[2]->getLeft();
		for(int i = 0; i < 3; ++i){
			(this->ptr)[i]->setdisp(this->disp);
			(this->ptr)[i]->setbl(true);
		}
	}

	else if((!vert) && (!tipup) && cl){
		Cell *temp = ((this->ptr)[2])->getUp();
		if((temp==nullptr)||(temp->getbl())){return;}
		temp = ((this->ptr)[2])->getDown();
		if((temp==nullptr)||(temp->getbl())){return;}
		temp = ((this->ptr)[3])->getDown();
		if((temp==nullptr)||(temp->getbl())){return;}
		
		for(int i = 0 ; i <= 3; ++i){
			(this->ptr)[i]->setdisp(' ');
			(this->ptr)[i]->setbl(false);
		}
		(this->ptr)[0] = ((this->ptr)[3])->getDown();
		(this->ptr)[1] = ((this->ptr)[2])->getDown();
		(this->ptr)[3] = ((this->ptr)[2])->getUp();

		for(int i = 0; i <= 3; ++i){
			(this->ptr)[i]->setdisp(this->disp);
			(this->ptr)[i]->setbl(true);
		}
	}

	else if(vert && (!tipup) && cl){
		Cell *temp = ((this->ptr)[0])->getUp();
		if((temp==nullptr)||(temp->getbl())){return;}
		temp = ((this->ptr)[1])->getRight();
		if((temp==nullptr)||(temp->getbl())){return;}
		for(int i = 2; i <=3; ++i){
			(this->ptr)[i]->setdisp(' ');
			(this->ptr)[i]->setbl(false);
		}
		(this->ptr)[0] = ((this->ptr)[0])->getUp();
		(this->ptr)[1] = ((this->ptr)[1])->getLeft();
		(this->ptr)[2] = ((this->ptr)[1])->getRight();
		(this->ptr)[3] = ((this->ptr)[2])->getRight();
		for(int i = 0; i <= 3; ++i){
			(this->ptr)[i]->setdisp(this->disp);
			(this->ptr)[i]->setbl(true);
		}
	}

	else if((!vert) && tipup && (!cl)){
		Cell *temp = (this->ptr)[2];
		for(int i = 0; i < 2; ++i){
			temp = temp->getUp();
			if((temp==nullptr)||(temp->getbl())){return;}
		}
		for(int i = 0; i <=3; ++i){
			(this->ptr)[i]->setdisp(' ');
			(this->ptr)[i]->setbl(false);
		}
		(this->ptr)[0] = (this->ptr)[1];
		(this->ptr)[1] = (this->ptr)[2];
		(this->ptr)[2] = ((this->ptr)[2])->getUp();
		(this->ptr)[3] = ((this->ptr)[2])->getUp();
		for(int i = 0; i <= 3; ++i){
			(this->ptr)[i]->setdisp(this->disp);
			(this->ptr)[i]->setbl(true);
		}
	}

	else if(vert && (!tipup) && (!cl)){
		Cell *temp = ((this->ptr)[0])->getUp();
		if((temp==nullptr)||(temp->getbl())){return;}
		for(int i = 0; i < 2; ++i){
			temp = temp->getRight();
			if((temp==nullptr)||(temp->getbl())){return;}
		}
		temp = temp->getDown();
		if((temp==nullptr)||(temp->getbl())){return;}
		for(int i = 0 ; i <= 3; ++i){
			(this->ptr)[i]->setdisp(' ');
			(this->ptr)[i]->setbl(false);
		}
		(this->ptr)[3] = ((this->ptr)[0])->getUp();
		(this->ptr)[2] = ((this->ptr)[3])->getRight();
		(this->ptr)[1] = ((this->ptr)[2])->getRight();
		(this->ptr)[0] = ((this->ptr)[1])->getDown();
		for(int i = 0; i <= 3; ++i){
			(this->ptr)[i]->setdisp(this->disp);
			(this->ptr)[i]->setbl(true);
		}
	}

	else if((!vert) && (!tipup) && (!cl)){
		Cell *temp = ((this->ptr)[3])->getUp();
		if((temp==nullptr)||(temp->getbl())){return;}
		temp = temp->getRight();
		if((temp==nullptr)||(temp->getbl())){return;}
		temp = ((this->ptr)[3])->getDown();
		if((temp==nullptr)||(temp->getbl())){return;}
		for(int i = 0 ; i <= 3; ++i){
			(this->ptr)[i]->setdisp(' ');
			(this->ptr)[i]->setbl(false);
		}
		(this->ptr)[0] = (((this->ptr)[3])->getUp())->getRight();
		(this->ptr)[1] = ((this->ptr)[0])->getLeft();
		(this->ptr)[2] = (this->ptr)[3];
		(this->ptr)[3] = ((this->ptr)[3])->getDown();
		for(int i = 0; i <= 3; ++i){
			(this->ptr)[i]->setdisp(this->disp);
			(this->ptr)[i]->setbl(true);
		}
	}

	else if(vert && tipup && (!cl)){
		Cell *temp = (this->ptr)[3];
		for(int i = 0; i < 2; ++i){
			temp = temp->getRight();
			if((temp==nullptr)||(temp->getbl())){return;}
		}
		for(int i = 0 ; i <= 3; ++i){
			(this->ptr)[i]->setdisp(' ');
			(this->ptr)[i]->setbl(false);
		}
		(this->ptr)[0] = (this->ptr)[2];
		(this->ptr)[1] = (this->ptr)[3];
		(this->ptr)[2] = ((this->ptr)[1])->getRight();
		(this->ptr)[3] = ((this->ptr)[2])->getRight();
		for(int i = 0; i <= 3; ++i){
			(this->ptr)[i]->setdisp(this->disp);
			(this->ptr)[i]->setbl(true);
		}
	}
}
