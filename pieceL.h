#ifndef PIECEL_H
#define PIECEL_H
#include "piece.h"
#include "cell.h"
#include <vector>

class PieceL: public Piece {
	public:
		PieceL(std::vector<std::vector<std::unique_ptr<Cell>>> &t);
		void transferPiece(std::vector<std::vector<std::unique_ptr<Cell>>> &src, std::vector<std::vector<std::unique_ptr<Cell>>> &des) override;
		void rotate(bool cl) override;
		~PieceL();
};

#endif
