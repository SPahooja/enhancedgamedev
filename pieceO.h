#ifndef PIECEO_H
#define PIECEO_H
#include "piece.h"
#include "cell.h"
#include <vector>

class PieceO: public Piece {
	public:
		PieceO(std::vector<std::vector<Cell*>> &t);
		void transferPiece(std::vector<std::vector<Cell*>> &src, std::vector<std::vector<Cell*>> &des);
		void rotate(bool cl);
		~PieceO();
};

#endif
