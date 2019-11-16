#include "piece.h"
#include "cell.h"
#include <iostream>
#include <vector>
using namespace std;

Piece::~Piece() {};

void Piece::movepos(string dir) {
	if (dir=="left") {
		bool val = true;
		for (int i=0; i < 4; i++) {
			if ((ptr[i]->getLeft()==nullptr)||(ptr[i]->getbl())) {
				val = false;
				break;
			}
		}
		if (val) {
			for (int i=0; i < 4; i++) {
				ptr[i]->setdisp(' ');
				ptr[i]->setbl(false);
			}
			for (int i=0; i < 4; i++) {
				ptr[i] = ptr[i]->getLeft();
				ptr[i]->setdisp(this->disp);
				ptr[i]->setbl(true);
			}
		}
	}
	else if (dir=="right") {
		bool val = true;
		for (int i=0; i < 4; i++) {
			if ((ptr[i]->getRight()==nullptr)||(ptr[i]->getbl())) {
				val = false;
				break;
			}
		}
		if (val) {
			for (int i=0; i < 4; i++) {
				ptr[i]->setdisp(' ');
				ptr[i]->setbl(false);
			}
			for (int i=0; i < 4; i++) {
				ptr[i] = ptr[i]->getRight();
				ptr[i]->setdisp(this->disp);
				ptr[i]->setbl(true);
			}
		}
	}
	else if (dir=="down") {
		bool val = true;
                for (int i=0; i < 4; i++) {
                        if ((ptr[i]->getDown()==nullptr)||(ptr[i]->getbl())) {
                                val = false;
                                break;
                        }
                }
                if (val) {
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
}

void Piece::drop() {
	while (true) {
		for (int i=0; i < 4; i++) {
			if ((ptr[i]->getDown()==nullptr)||(ptr[i]->getbl())) {
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
