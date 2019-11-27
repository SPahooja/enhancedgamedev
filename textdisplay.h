#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "state.h"
class Cell;

class TextDisplay: public Observer {
  std::vector<std::vector<char>> MainMap1;
  std::vector<std::vector<char>> MainMap2;
  std::vector<std::vector<char>> NextMap1;
  std::vector<std::vector<char>> NextMap2;
 public:
  TextDisplay();
  void notify(Subject &whoNotified) override;
  void printMain(std::ostream &out);
  void printNext(std::ostream &out);
};
#endif
