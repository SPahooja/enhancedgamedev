#ifndef PIECET_H
#define PIECET_H
#include "piece.h"
#include "cell.h"
#include <vector>

class PieceT: public Piece {
	public:
		PieceT(std::vector<std::vector<std::unique_ptr<Cell>>> &t);
		void transferPiece(std::vector<std::vector<std::unique_ptr<Cell>>> &src, std::vector<std::vector<std::unique_ptr<Cell>>> &des) override;
		void rotate(bool cl) override;
		~PieceT();
};

#endif
