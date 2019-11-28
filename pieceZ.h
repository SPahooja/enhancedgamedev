#ifndef PIECEZ_H
#define PIECEZ_H
#include "piece.h"
#include "cell.h"
#include <vector>

class PieceZ: public Piece {
    public:
        PieceZ(std::vector<std::vector<std::unique_ptr<Cell>>> &t);
	void transferPiece(std::vector<std::vector<std::unique_ptr<Cell>>> &src, std::vector<std::vector<std::unique_ptr<Cell>>> &des) override;
        void rotate(bool cl) override;
        ~PieceZ();
};

#endif
