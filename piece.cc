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
			condition = ((ptr[i]->getLeft()==nullptr)||((ptr[i]->getLeft()->getbl())&&(ptr[i]->getLeft()!=ptr[0])&&(ptr[i]->getLeft()!=ptr[1])&&(ptr[i]->getLeft()!=ptr[2])&&(ptr[i]->getLeft()!=ptr[3])));
		}
		else if (dir=="right") {
			condition = ((ptr[i]->getRight()==nullptr)||((ptr[i]->getRight()->getbl())&&(ptr[i]->getRight()!=ptr[0])&&(ptr[i]->getRight()!=ptr[1])&&(ptr[i]->getRight()!=ptr[2])&&(ptr[i]->getRight()!=ptr[3])));
		}
		else {
			condition = ((ptr[i]->getDown()==nullptr)||((ptr[i]->getDown()->getbl())&&(ptr[i]->getDown()!=ptr[0])&&(ptr[i]->getDown()!=ptr[1])&&(ptr[i]->getDown()!=ptr[2])&&(ptr[i]->getDown()!=ptr[3])));
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
			if ((ptr[i]->getDown()==nullptr)||((ptr[i]->getDown()->getbl())&&(ptr[i]->getDown()!=ptr[0])&&(ptr[i]->getDown()!=ptr[1])&&(ptr[i]->getDown()!=ptr[2])&&(ptr[i]->getDown()!=ptr[3]))) {
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
