#ifndef PIECET_H
#define PIECET_H
#include "piece.h"
#include "cell.h"
#include <vector>

class PieceT: public Piece {
	public:
		PieceT(std::vector<std::vector<Cell*>> &t);
		void transferPiece(std::vector<std::vector<Cell*>> &src, std::vector<std::vector<Cell*>> &des);
		void rotate(bool cl);
		~PieceT();
};

#endif
