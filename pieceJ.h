#ifndef PIECEJ_H
#define PIECEJ_H
#include "piece.h"
#include "cell.h"
#include <vector>

class PieceJ: public Piece {
	public:
		PieceJ(std::vector<std::vector<std::unique_ptr<Cell>>> &t);
		void transferPiece(std::vector<std::vector<std::unique_ptr<Cell>>> &src, std::vector<std::vector<std::unique_ptr<Cell>>> &des) override;
		void rotate(bool cl) override;
		~PieceJ();
};

#endif
