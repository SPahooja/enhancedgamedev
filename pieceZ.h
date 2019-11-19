#ifndef PIECEZ_H
#define PIECEZ_H
#include "piece.h"
#include "cell.h"
#include <vector>

class PieceZ: public Piece {
    public:
        PieceZ(std::vector<std::vector<Cell*>> &t);
        void rotate(bool cl);
        ~PieceZ();
};

#endif
