#ifndef PIECE_STAR_H
#define PIECE_STAR_H
#include "piece.h"
#include "cell.h"
#include <vector>

class PieceStar: public Piece {
	public:
		PieceStar(std::vector<std::vector<Cell*>> &t);
		void transferPiece(std::vector<std::vector<Cell*>> &src, std::vector<std::vector<Cell*>> &des);
		void rotate(bool cl);
		~PieceStar();
};

#endif
