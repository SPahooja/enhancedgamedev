#include "pieceJ.h"
#include "piece.h"
#include "cell.h"
#include <vector>
using namespace std;

PieceJ::PieceJ(vector<vector<Cell*>> &t) {
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
/*
void PieceJ::rotate(bool cl){}
	int anchor;
	bool vert;
	bool tipup = false;
	vector<Cell*> temp = (this->ptr);
	int row1 = (this->ptr)[0]->getrow();
	int col1 = (this->ptr)[0]->getcol();
	int row2 = (this->ptr)[1]->getrow();
	int col2 = (this->ptr)[1]->getcol();
	int row4 = (this->ptr)[3]->getrow();
	int col4 = (this->ptr)[3]->getcol();
	if (row2==row4) {
                vert = false;
                if (col2 < col4) {
                        anchor = 2;
                }
                else {
                        anchor = 4;		//<<<
                }
            //    if (((cl)&&(row1>=16))||((!cl)&&(row1<=1))) {
             //           return;
             //   }
		if (row4 < row1) {
			tipup = true;
		}
        }
        else if (col2==col4) {
                vert = true;
                if (row2 > row4) {
                        anchor = 3;
                }
                else {
                        anchor = 1;
                }
                if (col1>WHATEVER MAX -1) {		//<<<<<
                        return;
                }
		if (col4 < col1) {
			tipup = true;
		}
        }
	Cell *temp1 = (this->ptr)[0];
	Cell *temp2 = (this->ptr)[1];
	Cell *temp3 = (this->ptr)[2];
	Cell *temp4 = (this->ptr)[3];

	for(int i = 0; i < ; ++1){
		if(vert){
			if((cl&&tipup) || ((!cl)&&(!tipup))){
				temp3 = temp3->getRight();	//1 or weird excp
				if(temp3->getbl())
					return;
			}
			else if(tipup){
				temp4 = temp4->getRight();
				if(temp4->getbl())		//2
					return;
			}
			else {
				if(i == 0){
					temp1 = temp1->getUp();
					if(temp1->getbl())
						return;
				}
				else{
					temp2 = temp2->getRight();
					if(temp2->getbl())
						return;
				}
			}
		}
		else{




*/







void PieceJ::rotate(bool cl){
	int anchor;
	bool vert;
	bool tipup = false;
	vector<Cell*> temp = (this->ptr);
	int row1 = (this->ptr)[0]->getrow();
	int col1 = (this->ptr)[0]->getcol();
	int row2 = (this->ptr)[1]->getrow();
	int col2 = (this->ptr)[1]->getcol();
	int row3 = (this->ptr)[2]->getrow();
	int col3 = (this->ptr)[2]->getcol();
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
			if(temp->getbl()){
				return;
			}
		}
		temp = temp->getRight();
		if(temp->getbl()){return;}

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
