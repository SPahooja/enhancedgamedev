#include "graphicdisplay.h"
#include "cell.h"
#include "observer.h"
#include "subject.h"
#include "state.h"
#include "window.h"
#include <cstddef>
using namespace std;

GraphicDisplay::GraphicDisplay() {
	xw.fillRectangle(0, 0, 500, 500, 0);
	xw.fillRectangle(220, 0, 60, 500, 1);
	xw.fillRectangle(0, 400, 500, 20, 1);
}

void GraphicDisplay::notify(Subject &whoNotified) {}

void GraphicDisplay::updateStats(int lev1, int scr1, int hscr1, int lev2, int scr2, int hscr2) {}
