#ifndef PIECES_H
#define PIECES_H
#include "piece.h"
#include "cell.h"
#include <vector>

class PieceS: public Piece {
    public:
        PieceS(std::vector<std::vector<std::unique_ptr<Cell>>> &t);
	void transferPiece(std::vector<std::vector<std::unique_ptr<Cell>>> &src, std::vector<std::vector<std::unique_ptr<Cell>>> &des) override;
        void rotate(bool cl) override;
        ~PieceS();
};

#endif
