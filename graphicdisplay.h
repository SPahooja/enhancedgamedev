#ifndef GRAPHICDISPLAY_H
#define GRAPHICDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "state.h"
#include "window.h"
#include "grid.h"
class Cell;

class GraphicDisplay: public Observer {
  Xwindow xw;
 public:
  GraphicDisplay(int lev1, int hscr1, int lev2, int hscr2);
  void notify(Subject &whoNotified) override;
  void updateStats(int lev1, int scr1, int hscr1, int lev2, int scr2, int hscr2);
};

#endif
