#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "grid.h"
#include "cell.h"
#include "autocommand.h"
using namespace std;

int main(int argc, char *argv[]) {
  cin.exceptions(ios::eofbit|ios::failbit);
  Grid g;
  string cmd;
  bool seq = false;
  ifstream file;
  vector<string> coms;
  g.nextBlock(1);
  g.nextBlock(2);
  system("clear");
  cout << g;
  cout << "PLAYER 1'S TURN" << endl;
  int pl = 0;
  try {
  	while (true) {
    		if (seq) {
			if (!(file >> cmd)) { seq = false; }
		}
		if (!seq) {
			cin >> cmd;
		}
    		coms = autocommand(cmd);
    		if (coms.size()==0) {
    		}
   		else if ((coms[0]=="right")||(coms[0]=="left")||(coms[0]=="down")) {
	    		for (int i=0; i < coms.size(); i++) {
			    	g.moveBlock((pl%2)+1, coms[0]);
	   	 	}
			int lev = g.getLevel((pl%2)+1);
			if (lev>=3) {
				g.moveBlock((pl%2)+1, "down");
			}
			bool h = g.getHeavy((pl%2)+1);
			if ((h)&&(coms[0]!="down")) {
				g.moveBlock((pl%2)+1, "down");
				g.moveBlock((pl%2)+1, "down");
			}
	    		cout << g;
    		}
    		else if (coms[0]=="clockwise") {
	    		for (int i=0; i < coms.size(); i++) {
		    		g.rotateBlock((pl%2)+1, true);
	    		}
			int lev = g.getLevel((pl%2)+1);
                        if (lev>=3) {
                                g.moveBlock((pl%2)+1, "down");
                        }
	    		cout << g;
    		}
    		else if (coms[0]=="counterclockwise") {
			for (int i=0; i < coms.size(); i++) {
				g.rotateBlock((pl%2)+1, false);
			}
			int lev = g.getLevel((pl%2)+1);
                        if (lev>=3) {
                                g.moveBlock((pl%2)+1, "down");
                        }
			cout << g;
		}
    		else if (coms[0]=="drop") {
			g.setHeavy((pl%2)+1, false);
			int x = 0;
			x+=g.dropBlock((pl%2)+1);
			try {
				if (coms.size()>1) {
	    				for (int i=1; i<coms.size(); i++) {
						g.nextBlock((pl%2)+1);
	    					x+=g.dropBlock((pl%2)+1);
	    				}
				}
				if (x>1) {
					cout << "PLAYER " << (pl%2)+1 << " HAS ACTIVATED A SPECIAL ACTION!" << endl;
					cout << "PLEASE ENTER force, heavy, or blind" << endl;
					if (seq) {
						if (!(file >> cmd)) { seq = false; }
					}
					if (!seq) {
						cin >> cmd;
					}
					coms = autocommand(cmd);
					if (coms[0]=="force") {
						while(true){
							cout << "Choose one of I, J, L, O, S, Z or T" << endl;
							if (seq) {
								if (!(file >> cmd)) { seq = false; }
							}
							if (!seq) {
								cin >> cmd;
							}
							if(cmd=="I" ||cmd=="J" ||cmd=="L" ||cmd=="O" ||cmd=="S" ||cmd=="Z" ||cmd=="T"){
								g.forceNext(((pl+1)%2)+1, cmd);
								break;
							}
						}
					}
					else if (coms[0]=="heavy") {
						g.setHeavy(((pl+1)%2)+1, true);
					}
					else if (coms[0]=="blind") {
						g.bldPlay(((pl+1)%2)+1);
					}
				}
				g.nextBlock((pl%2)+1);
	    			++pl;
	    			cout << g;
				cout  << "PLAYER " << (pl%2)+1 << "'S TURN"  << endl;
			}
			catch (const invalid_argument &r) {
				cout << "PLAYER " << ((pl+1)%2)+1 << " HAS WON THE GAME!" << endl;
				return 0;
			}
    		}
		else if ((coms[0]=="levelup")||(coms[0]=="leveldown")) {
			bool st = coms[0]=="levelup"?true:false;
			for (int i=0; i < coms.size(); i++) {
				g.chngLevel((pl%2)+1, st);
			}
		}
		else if (coms[0]=="norandom") {
			if (seq) {
				if (!(file >> cmd)) { seq = false; }
			}
			if (!seq) {
				cin >> cmd;
			}
			g.chngRandom((pl%2)+1, cmd);
		}
		else if (coms[0]=="random") {
			g.chngRandom((pl%2)+1, "");
		}
		else if (coms[0]=="sequence") {
			if (seq) {
				if (!(file >> cmd)) { seq = false; }
			}
			if  (!seq) {
				cin >> cmd;
			}
			file.open(cmd);
			seq = true;
		}
		else if (coms[0]=="restart") {
			  g.restartGame();
			  g.nextBlock(1);
			  g.nextBlock(2);
			  cout << g;
			  cout << "PLAYER 1'S TURN" << endl;
		}
  	}
  }
  catch (ios::failure &) {
	  int x = g.getWinner();
	  if (x==0) {
		  cout << "PLAYER 1 and 2 TIED IN THE GAME!" << endl;
	  }
	  else {
		  cout << "PLAYER " << x << " HAS WON THE GAME!" << endl;
	  }
  }  // Any I/O failure quits
}

