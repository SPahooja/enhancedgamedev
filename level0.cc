#include "level.h"
#include "level0.h"
#include "piece.h"
#include "pieceI.h"
#include "pieceO.h"
#include "pieceT.h"
#include "pieceS.h"
#include "pieceZ.h"
#include "cell.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

LevelZero::LevelZero() {
	pos1 = 0;
	ifstream file1{"sequence1.txt"};
	len1 = 0;
	string p;
	while (file1 >> p) { ++len1; }
	pos2 = 0;
	ifstream file2{"sequence2.txt"};
	len2 = 0;
	while (file2 >> p) { ++len2; }
}

Piece* LevelZero::nextPiece(int p, vector<vector<Cell*>> &t) {
	string piece;
	if (p==1) {
		ifstream file1{"sequence1.txt"};
		for (int i=0; i<=pos1; i++) {
			file1 >> piece;
		}
		++pos1;
		if (pos1==len1) {
			pos1 = 0;
		}
	}
	else {
		ifstream file2{"sequence2.txt"};
                for (int i=0; i<=pos2; i++) {
                        file2 >> piece;
                }
		++pos2;
		if (pos2==len2) {
			pos2 = 0;
		}
	}
	Piece *pc = nullptr;
	if (piece=="I") {
		pc = new PieceI(t);
	}
	else if (piece=="O") {
		pc = new PieceO(t);
	}
	else if (piece=="T") {
		pc = new PieceT(t);
	}
	else if (piece=="S") {
		pc = new PieceS(t);
	}
	else if (piece=="Z") {
		pc = new PieceZ(t);
	}
	return pc;
}
