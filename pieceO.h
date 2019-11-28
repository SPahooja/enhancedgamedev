#ifndef PIECEO_H
#define PIECEO_H
#include "piece.h"
#include "cell.h"
#include <vector>

class PieceO: public Piece {
	public:
		PieceO(std::vector<std::vector<std::unique_ptr<Cell>>> &t);
		void transferPiece(std::vector<std::vector<std::unique_ptr<Cell>>> &src, std::vector<std::vector<std::unique_ptr<Cell>>> &des) override;
		void rotate(bool cl) override;
		~PieceO();
};

#endif
