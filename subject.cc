#include "subject.h"

void Subject::attach(Observer *o) {
  	observers.emplace_back(o);
}

void Subject::clear() {
	for (int i=0; i<observers.size(); i++) {
		observers.pop_back();
	}
}

void Subject::notifyObservers() {
  for (auto &ob : observers) ob->notify(*this);
}

void Subject::setState(State newS) { state = newS; }

State Subject::getState() const { return state; }
