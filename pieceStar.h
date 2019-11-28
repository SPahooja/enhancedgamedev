#ifndef PIECE_STAR_H
#define PIECE_STAR_H
#include "piece.h"
#include "cell.h"
#include <vector>

class PieceStar: public Piece {
	public:
		PieceStar(std::vector<std::vector<std::unique_ptr<Cell>>> &t);
		void transferPiece(std::vector<std::vector<std::unique_ptr<Cell>>> &src, std::vector<std::vector<std::unique_ptr<Cell>>> &des) override;
		void rotate(bool cl) override;
		~PieceStar();
};

#endif
