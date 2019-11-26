#include "level4.h"
#include <vector>
#include <cstdlib>
using namespace std;

LevelFour::LevelFour(int s, string file) {
        srand(s);
        this->pos = 0;
        this->len = 0;
        this->file = file;
        if (file!="") {
                this->random = false;
                ifstream fl{file};
                string temp;
                while (fl >> temp) { ++len; }
        }
        else {
                this->random = true;
        }
}

Piece* LevelFour::nextPiece(vector<vector<Cell*>> &t) {
        int rd = 0;
        string mv = "";
        if (!(random)) {
                ifstream doc{file};
                for (int i=0; i<=pos; i++) {
                        doc >> mv;
                }
                ++pos;
                if (pos==len) {
                        pos = 0;
                }
        }
        else {
                rd = rand()%9+1;
        }
        Piece *pc = nullptr;
        if ((rd==1)||(rd==2)||(mv=="Z")) {
                pc = new PieceZ(t);
        }
        else if ((rd==3)||(rd==4)||(mv=="S")) {
                pc = new PieceS(t);
        }
        else if ((rd==5)||(mv=="I")) {
                pc = new PieceI(t);
        }
        else if ((rd==6)||(mv=="O")) {
                pc = new PieceO(t);
        }
        else if ((rd==7)||(mv=="T")) {
                pc = new PieceT(t);
        }
        else if ((rd==8)||(mv=="J")) {
                pc = new PieceJ(t);
        }
        else if ((rd==9)||(mv=="L")) {
                pc = new PieceL(t);
        }
    return pc;
}

