#include "graphicdisplay.h"
#include "cell.h"
#include "observer.h"
#include "subject.h"
#include "state.h"
#include "window.h"
#include <cstddef>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

GraphicDisplay::GraphicDisplay(int lev1, int hscr1, int lev2, int hscr2) {
	xw.fillRectangle(0, 0, 500, 500, 0);
	xw.fillRectangle(0, 400, 500, 20, 1); //Next bar
	xw.fillRectangle(220, 0, 60, 500, 1); //Player separator
	this->updateStats(lev1, 0, hscr1, lev2, 0, hscr2);
	char pcs[9] = {' ', '-', 'I', 'O', 'T', 'Z', 'S', 'J', 'L'};
	for (int i=0; i<9; i++) {
		colourmap[pcs[i]] = i;
	}
}

void GraphicDisplay::notify(Subject &whoNotified) {
	State tp = whoNotified.getState();
	if (tp.p==Position::MainMap1) {
		xw.fillRectangle(20 * tp.col, 40 + 20 * tp.row, 20, 20, colourmap[tp.disp]);
	}
	else if (tp.p==Position::MainMap2) {
		xw.fillRectangle(280 + 20 * tp.col, 40 + 20 * tp.row, 20, 20, colourmap[tp.disp]);
	}
	else if (tp.p==Position::NextMap1) {
		xw.fillRectangle(20 * tp.col, 420 + 20 * tp.row, 20, 20, colourmap[tp.disp]);
	}
	else if (tp.p==Position::NextMap2) {
		xw.fillRectangle(280 + 20 * tp.col, 420 + 20 * tp.row, 20, 20, colourmap[tp.disp]);
	}
}

void GraphicDisplay::updateStats(int lev1, int scr1, int hscr1, int lev2, int scr2, int hscr2) {
	xw.fillRectangle(0, 0, 500, 40, 1); //Cover old scores
	xw.drawString(10, 10, "Level: " + to_string(lev1), 0);
        xw.drawString(10, 24, "Score: " + to_string(scr1), 0);
        xw.drawString(10, 38, "H Scr: " + to_string(hscr1), 0);
        xw.drawString(290, 10, "Level: " + to_string(lev2), 0);
        xw.drawString(290, 24, "Score: " + to_string(scr2), 0);
        xw.drawString(290, 38, "H Scr: " + to_string(hscr2), 0);
}
