#ifndef PIECEJ_H
#define PIECEJ_H
#include "piece.h"
#include "cell.h"
#include <vector>

class PieceJ: public Piece {
	public:
		PieceJ(std::vector<std::vector<Cell*>> &t);
		void rotate(bool cl);
		~PieceJ();
};

#endif
