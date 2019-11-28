#ifndef PIECEI_H
#define PIECEI_H
#include "piece.h"
#include "cell.h"
#include <vector>
#include <memory>

class PieceI: public Piece {
	public:
		PieceI(std::vector<std::vector<std::unique_ptr<Cell>>> &t);
		void transferPiece(std::vector<std::vector<std::unique_ptr<Cell>>> &src, std::vector<std::vector<std::unique_ptr<Cell>>> &des) override;
		void rotate(bool cl) override;
		~PieceI();
};

#endif
