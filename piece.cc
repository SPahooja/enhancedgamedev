#include "piece.h"
#include "cell.h"
#include <iostream>
#include <vector>
using namespace std;

Piece::~Piece() {
	for (int i=0; i<4; i++) {
		if ((this->ptr)[i]!=nullptr) {
			(this->ptr)[i]->setdisp(' ');
			(this->ptr)[i]->setbl(false);
		}
	}
}

void Piece::movepos(string dir, int c) {
	for (int i=0; i < 4; i++) {
                ptr[i]->setdisp(' ');
                ptr[i]->setbl(false);
        }
	bool cont = true;
	while ((cont)&&(c>0)) {
		bool condition;
		for (int i=0; i < 4; i++) {
			if (dir=="left") {
				condition = ((ptr[i]->getLeft()==nullptr)||((ptr[i]->getLeft()->getbl())&&(ptr[i]->getLeft()!=ptr[0])&&(ptr[i]->getLeft()!=ptr[1])&&(ptr[i]->getLeft()!=ptr[2])&&(ptr[i]->getLeft()!=ptr[3])));
			}
			else if (dir=="right") {
				condition = ((ptr[i]->getRight()==nullptr)||((ptr[i]->getRight()->getbl())&&(ptr[i]->getRight()!=ptr[0])&&(ptr[i]->getRight()!=ptr[1])&&(ptr[i]->getRight()!=ptr[2])&&(ptr[i]->getRight()!=ptr[3])));
			}
			else {
				condition = ((ptr[i]->getDown()==nullptr)||((ptr[i]->getDown()->getbl())&&(ptr[i]->getDown()!=ptr[0])&&(ptr[i]->getDown()!=ptr[1])&&(ptr[i]->getDown()!=ptr[2])&&(ptr[i]->getDown()!=ptr[3])));
			}
			if (condition) {
				cont = false;
			}
		}
		if (cont) {
			for (int i=0; i < 4; i++) {
				if (dir=="left") {
					ptr[i] = ptr[i]->getLeft();
                		}
                		else if (dir=="right") {
                        		ptr[i] = ptr[i]->getRight();
                		}
                		else {
                        		ptr[i] = ptr[i]->getDown();
                		}
			}
		}
		--c;
	}
	for (int i=0; i < 4; i++) {
		ptr[i]->setdisp(this->disp);
		ptr[i]->setbl(true);
	}
}

void Piece::rowdel(int j) {
	for (int i=0; i < 4; i++) {
		if (ptr[i]!=nullptr) {
			ptr[i]->setdisp(' ');
			ptr[i]->setbl(false);
		}
	}
	for (int i=0; i < 4; i++) {
		if (ptr[i]!=nullptr) {
			if (ptr[i]->getrow()==j) {
				ptr[i] = nullptr;
			}
			else if (ptr[i]->getrow()<j) {
				ptr[i] = ptr[i]->getDown();
			}
		}
		if (ptr[i]!=nullptr) {
			ptr[i]->setdisp(this->disp);
			ptr[i]->setbl(true);
		}
	}
}

void Piece::drop() {
	for (int i=0; i<4; i++) {
		ptr[i]->setdisp(' ');
		ptr[i]->setbl(false);
	}
	bool cont = true;
	while (cont) {
		for (int i=0; i < 4; i++) {
			if ((ptr[i]->getDown()==nullptr)||((ptr[i]->getDown()->getbl())&&(ptr[i]->getDown()!=ptr[0])&&(ptr[i]->getDown()!=ptr[1])&&(ptr[i]->getDown()!=ptr[2])&&(ptr[i]->getDown()!=ptr[3]))) {
				cont = false;
			}
		}
		if (cont) {
			for (int i=0; i<4; i++) {
				ptr[i] = ptr[i]->getDown();
			}
		}
	}
	for (int i=0; i < 4; i++) {
		ptr[i]->setdisp(this->disp);
		ptr[i]->setbl(true);
	}
}
