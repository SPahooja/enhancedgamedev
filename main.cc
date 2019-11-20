#include <iostream>
#include <string>
#include <vector>
#include "grid.h"
#include "cell.h"
#include "autocommand.h"
using namespace std;

int main(int argc, char *argv[]) {
  cin.exceptions(ios::eofbit|ios::failbit);
  Grid g;
  string cmd;
  g.nextBlock(1);
  cout << g;
  int pl = 0;
  try {
  	while (true) {
    		cin >> cmd;
    		vector<string> coms = autocommand(cmd);
    		if (coms.size()==0) {
    		}
   		else if ((coms[0]=="right")||(coms[0]=="left")||(coms[0]=="down")) {
	    		for (int i=0; i < coms.size(); i++) {
			    	g.moveBlock((pl%2)+1, coms[0]);
	   	 	}
	    		cout << g;
    		}
    		else if (coms[0]=="clockwise") {
	    		for (int i=0; i < coms.size(); i++) {
		    		g.rotateBlock((pl%2)+1, true);
	    		}
	    		cout << g;
    		}
    		else if (coms[0]=="counterclockwise") {
			for (int i=0; i < coms.size(); i++) {
				g.rotateBlock((pl%2)+1, false);
			}
			cout << g;
		}
    		else if (coms[0]=="drop") {
			g.dropBlock((pl%2)+1);
			if (coms.size()>1) {
	    			for (int i=1; i<coms.size(); i++) {
					g.nextBlock((pl%2)+1);
	    				g.dropBlock((pl%2)+1);
	    			}
			}
	    		++pl;
	    		g.nextBlock((pl%2)+1);
	    		cout << g;
    		}
  	}
  }
  catch (ios::failure &) {}  // Any I/O failure quits
}

