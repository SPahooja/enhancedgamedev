#include "textdisplay.h"
#include "cell.h"
#include "observer.h"
#include "subject.h"
#include "state.h"
#include <cstddef>
using namespace std;

TextDisplay::TextDisplay() {
	for (int i=0; i < 18; i++) {
		vector<char> temp1(11, ' ');
		vector<char> temp2(11, ' ');
		MainMap1.push_back(temp1);
		MainMap2.push_back(temp2);
		if (i < 4) {
			vector<char> temp3(11, ' ');
			vector<char> temp4(11, ' ');
			NextMap1.push_back(temp3);
			NextMap2.push_back(temp4);
		}
	}
}

void TextDisplay::notify(Subject &whoNotified) {
	State tp = whoNotified.getState();
	if (tp.p==Position::MainMap1) {
		this->MainMap1[tp.row][tp.col] = tp.disp;
	}
	else if (tp.p==Position::MainMap2) {
		this->MainMap2[tp.row][tp.col] = tp.disp;
	}
	else if (tp.p==Position::NextMap1) {
		this->NextMap1[tp.row][tp.col] = tp.disp;
	}
	else if (tp.p==Position::NextMap2) {
		this->NextMap2[tp.row][tp.col] = tp.disp;
	}
}

void TextDisplay::printMain(ostream &out) {
	for (int i=0; i < 18; i++) {
                for (int j=0; j < 11; j++) {
			out << MainMap1[i][j];
                }
                for (int j=0; j < 5; j++) {
                        out << ' ';
                }
                for (int j=0; j < 11; j++) {
			out << MainMap2[i][j];
                }
                out << endl;
        }
}

void TextDisplay::printNext(ostream &out) {
	for (int i=0; i < 4; i++) {
                for (int j=0; j < 11; j++) {
                        out << NextMap1[i][j];
                }
                for (int j=0; j < 5; j++) {
                        out << ' ';
                }
                for (int j=0; j < 11; j++) {
                        out << NextMap2[i][j];
                }
                out << endl;
        }
}
