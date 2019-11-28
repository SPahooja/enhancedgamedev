#include "subject.h"
#include <iostream>
using namespace std;

void Subject::attach(Observer *o) {
  	observers.emplace_back(o);
}

void Subject::clear() { observers.clear(); }

void Subject::notifyObservers() {
  for (auto &ob : observers) ob->notify(*this);
}

void Subject::setState(State newS) { state = newS; }

State Subject::getState() const { return state; }
