#include "piece.h"
#include "cell.h"
#include <iostream>
#include <vector>
using namespace std;

Piece::~Piece() {};

void Piece::movepos(string dir) {
	bool condition;
	for (int i=0; i < 4; i++) {
		if (dir=="left") {
			condition = ((ptr[i]->getLeft()==nullptr)||((ptr[i]->getLeft()->getdisp()!=this->disp)&&(ptr[i]->getLeft()->getdisp()!=' ')));
		}
		else if (dir=="right") {
			condition = ((ptr[i]->getRight()==nullptr)||((ptr[i]->getRight()->getdisp()!=this->disp)&&(ptr[i]->getRight()->getdisp()!=' ')));
		}
		else {
			condition = ((ptr[i]->getDown()==nullptr)||((ptr[i]->getDown()->getdisp()!=this->disp)&&(ptr[i]->getDown()->getdisp()!=' ')));
		}
		if (condition) {
			return;
		}
	}
	for (int i=0; i < 4; i++) {
		ptr[i]->setdisp(' ');
		ptr[i]->setbl(false);
	}
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
		ptr[i]->setdisp(this->disp);
		ptr[i]->setbl(true);
	}
}

void Piece::drop() {
	while (true) {
		for (int i=0; i < 4; i++) {
			if ((ptr[i]->getDown()==nullptr)||(ptr[i]->getDown()->getbl())) {
				return;
			}
		}
		for (int i=0; i < 4; i++) {
			ptr[i]->setdisp(' ');
			ptr[i]->setbl(false);
		}
		for (int i=0; i < 4; i++) {
			ptr[i] = ptr[i]->getDown();
			ptr[i]->setdisp(this->disp);
			ptr[i]->setbl(true);
		}
	}
}
