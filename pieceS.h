#ifndef PIECES_H
#define PIECES_H
#include "piece.h"
#include "cell.h"
#include <vector>

class PieceS: public Piece {
    public:
        PieceS(std::vector<std::vector<Cell*>> &t);
        void rotate(bool cl);
        ~PieceS();
};

#endif
