#include "level.h"
#include "level0.h"
#include "piece.h"
#include "pieceI.h"
#include "pieceO.h"
#include "pieceT.h"
#include "pieceS.h"
#include "pieceZ.h"
#include "pieceJ.h"
#include "cell.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

LevelZero::LevelZero(string s) {
	pos = 0;
	fl = s;
	ifstream file1{s};
	len = 0;
	string p;
	while (file1 >> p) { ++len; }
}

Piece* LevelZero::nextPiece(vector<vector<Cell*>> &t) {
	string piece;
	ifstream file1{fl};
	for (int i=0; i<=pos; i++) {
		file1 >> piece;
	}
	++pos;
	if (pos==len) {
		pos = 0;
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
	else if (piece=="J") {
		pc = new PieceJ(t);
	}
	return pc;
}
