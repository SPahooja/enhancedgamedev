#include "grid.h"
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

Grid::Grid(int lev1, int lev2) {
	setmap(this->map1);
	setmap(this->map2);
	this->lev1 = lev1;
	this->lev2 = lev2;
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
	return out;
}

Grid::~Grid() {}
