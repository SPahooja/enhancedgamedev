#include <iostream>
#include <string>
#include <vector>
#include "grid.h"
#include "cell.h"
using namespace std;

int main(int argc, char *argv[]) {
  cin.exceptions(ios::eofbit|ios::failbit);
  Grid p1;
  Grid p2;
  int i = 0;
  try {
  while (true) {
    cin >> cmd;
    if (cmd == "new") {
      int n;
      cin >> n;
      g.init(n);
      cout << g;
    }
    else if (cmd == "play") {
      int r = 0, c = 0;
      cin >> r >> c;
      // Check if invalid move exception is thrown
      try {
	      i%2==0?g.setPiece(r, c, Colour::Black):g.setPiece(r, c, Colour::White);
	      ++i;
	      cout << g;
      }
      catch (...) {}
      // Check if the board is full. If yes, check you won.
      bool comp = g.isFull();
      if (comp) {
	      Colour tp = g.whoWon();
	      if (tp==Colour::Black) {
		      cout << "Black Wins!" << endl;
	      }
	      else if (tp==Colour::White) {
		      cout << "White Wins!" << endl;
	      }
	      else {
		      cout << "Tie!" << endl;
	      }
	      return 0;
      }
    }
  }
  }
  catch (ios::failure &) {}  // Any I/O failure quits
}

