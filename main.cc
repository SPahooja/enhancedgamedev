#include <iostream>
#include <string>
#include <vector>
#include "grid.h"
#include "cell.h"
using namespace std;

int main(int argc, char *argv[]) {
  cin.exceptions(ios::eofbit|ios::failbit);
  Grid g;
  string cmd;
  int i = 0;
  try {
  while (true) {
    cin >> cmd;
    if (cmd == "new") {
      g.nextBlock(1);
      cout << g;
    }
    else if ((cmd == "right") || (cmd=="left") || (cmd=="down")) {
	    g.moveBlock(1, cmd);
	    cout << g;
    }
    else if (cmd=="rotate") {
	    g.rotateBlock(1, true);
	    cout << g;
    }
    else if (cmd=="drop") {
	    g.dropBlock(1);
	    cout << g;
    }
  }
  }
  catch (ios::failure &) {}  // Any I/O failure quits
}

