#include "grid.h"
#include "piece.h"
#include "pieceI.h"
#include "pieceO.h"
#include "pieceT.h"
#include "pieceZ.h"
#include "pieceS.h"
#include "level0.h"
#include "level1.h"
#include <iostream>
#include <vector>
using namespace std;

void setmap(vector<vector<Cell*>> &mp) {
	for (int i=0; i < 18; i++) {
                vector<Cell*> temp;
                for (int j=0; j < 11; j++) {
                        Cell *tp = new Cell{i, j};
                        temp.push_back(tp);
                }
                mp.push_back(temp);
        }
	for (int i=0; i < 18; i++) {
                for (int j=0; j < 11; j++) {
                        Cell* l = j!=0?mp[i][j-1]:nullptr;
                        Cell* r = j!=10?mp[i][j+1]:nullptr;
                        Cell* u = i!=0?mp[i-1][j]:nullptr;
                        Cell* d = i!=17?mp[i+1][j]:nullptr;
                        (mp[i][j])->setDir(l, r, u, d);
                }
        }
}

void setnext(vector<vector<Cell*>> &mp) {
        for (int i=0; i < 4; i++) {
                vector<Cell*> temp;
                for (int j=0; j < 11; j++) {
                        Cell *tp = new Cell{i, j};
                        temp.push_back(tp);
                }
                mp.push_back(temp);
        }
}

Level* makeLevel(int n, int p) {
	Level *lo = nullptr;
	if (n==0) {
		string s = p==1?"sequence1.txt":"sequence2.txt";
		lo = new LevelZero(s);
	}
	else if (n==1) {
		lo = new LevelOne(0);
	}
	// More cases here
	return lo;
}

Grid::Grid(int l1, int l2) {
	setmap(this->map1);
	setmap(this->map2);
	setnext(this->nxtmap1);
	setnext(this->nxtmap2);
	this->lev1 = l1;
	this->lev2 = l2;
	this->lp1 = makeLevel(lev1, 1);
	this->lp2 = makeLevel(lev2, 2);
	this->nxtpc1 = lp1->nextPiece(nxtmap1);
	this->nxtpc2 = lp2->nextPiece(nxtmap2);
	this->curscore1 = 0;
	this->curscore2 = 0;
}

void repeatprinter(ostream &out, string s, int rep, int spc) {
	for (int m=0; m < rep; m++) {
                out << s;
        }
        for (int m=0; m < spc; m++) {
                out << " ";
        }
        for (int m=0; m < rep;  m++) {
                out << s;
        }
	out << endl;
}

ostream &operator<<(ostream &out, const Grid &g) {
	out << "Level: " << g.lev1 << "        Level: " << g.lev2 << endl;
	out << "Score: " << g.curscore1 << "        Score: " << g.curscore2 << endl;
	repeatprinter(out, "-", 11, 5);
	for (int i=0; i < 18; i++) {
		for (int j=0; j < 11; j++) {
			out << ((g.map1)[i][j])->getdisp();
		}
		for (int j=0; j < 5; j++) {
			out << ' ';
		}
		for (int j=0; j < 11; j++) {
			out << ((g.map2)[i][j])->getdisp();
		}
		out << endl;
	}
	repeatprinter(out, "-", 11, 5);
	out << "Next:           Next:" << endl;
	for (int i=0; i < 4; i++) {
		for (int j=0; j < 11; j++) {
			out << ((g.nxtmap1)[i][j])->getdisp();
		}
		for (int j=0; j < 5; j++) {
			out << ' ';
		}
		for (int j=0; j < 11; j++) {
			out << ((g.nxtmap2)[i][j])->getdisp();
		}
		out << endl;
	}
	return out;
}

Grid::~Grid() {
	for (int i=0; i < 18; i++) {
		for (int j=0; j < 11; j++) {
			delete map1[i][j];
			delete map2[i][j];
		}
	}
	for (int i=0; i < move1.size(); i++) {
		delete move1[i];
	}
	for (int j=0; j < move2.size(); j++) {
		delete move2[j];
	}
	delete lp1;
	delete lp2;
}

void Grid::nextBlock(int p) {
	if (p==1) {
		this->nxtpc1->transferPiece(nxtmap1, map1);
		cout << "here" << endl;
		move1.push_back(this->nxtpc1);
		this->nxtpc1 = lp1->nextPiece(nxtmap1);
	}
	else {
		this->nxtpc2->transferPiece(nxtmap2, map2);
		move2.push_back(this->nxtpc2);
		this->nxtpc2 = lp2->nextPiece(nxtmap2);
	}
}

void  Grid::rotateBlock(int p, bool clock) {
	if (p==1) {
		move1[move1.size()-1]->rotate(clock);
	}
	else {
		move2[move2.size()-1]->rotate(clock);
	}
}

void Grid::moveBlock(int p, string dir) {
	if (p==1) {
		move1[move1.size()-1]->movepos(dir);
	}
	else {
		move2[move2.size()-1]->movepos(dir);
	}
}

void  Grid::dropBlock(int p) {
        if (p==1) {
                move1[move1.size()-1]->drop();
		for (int j=17; j>=0; j--) {
			for (int i=0; i < 11; i++) {
				if (!(map1[17][i]->getbl())) {
					return;
				}
			}
			curscore1 += (lev1 + 1) * (lev1 + 1);
			for (int i=0; i < move1.size(); i++) {
				move1[i]->rowdel();
			}
		}
        }
        else {
                move2[move2.size()-1]->drop();
		for (int j=17; j>=0; j--) {
			for (int i=0; i < 11; i++) {
                        	if (!(map2[17][i]->getbl())) {
                                	return;
                        	}
                	}
			curscore2 += (lev2 + 1) * (lev2 + 1);
                	for (int i=0; i < move2.size(); i++) {
                       		move2[i]->rowdel();
                	}
		}
        }
}

void Grid::chngLevel(int p, bool up) {
	if (p==1) {
		delete lp1;
		lev1= up?lev1+1:lev1-1;
		lp1 = makeLevel(lev1, p);
	}
	else {
		delete lp2;
		lev2= up?lev2+1:lev2-1;
		lp2 = makeLevel(lev2, p);
	}
}
