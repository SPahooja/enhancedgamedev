#ifndef PIECEI_H
#define PIECEI_H
#include "piece.h"
#include "cell.h"
#include <vector>

class PieceI: public Piece {
	public:
		PieceI(std::vector<std::vector<Cell*>> &t);
		void rotate(bool cl);
		~PieceI();
};

#endif
