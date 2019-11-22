#ifndef PIECEL_H
#define PIECEL_H
#include "piece.h"
#include "cell.h"
#include <vector>

class PieceL: public Piece {
	public:
		PieceL(std::vector<std::vector<Cell*>> &t);
		void transferPiece(std::vector<std::vector<Cell*>> &src, std::vector<std::vector<Cell*>> &des);
		void rotate(bool cl);
		~PieceL();
};

#endif
