#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "grid.h"
#include "cell.h"
#include "autocommand.h"
using namespace std;

int main(int argc, char *argv[]) {
	string sf1 = "sequence1.txt";
	string sf2 = "sequence2.txt";
	int seed = 0;
	int lev1 = 0;
	int lev2 = 0;
	bool grph = true;
	int i=1;
	while (i<argc) {
		string temp = argv[i];
		if (temp=="-text") {
			grph = false;
		}
		if (temp=="-seed") {
			istringstream sock(argv[i+1]);
			sock >> seed;
			++i;
		}
		if (temp=="-scriptfile1") {
			sf1 = argv[i+1];
			++i;
		}
		if (temp=="-scriptfile2") {
			sf2 = argv[i+1];
			++i;
		}
		if (temp=="-startlevel") {
			istringstream sock(argv[i+1]);
			sock >> lev1;
			lev2 = lev1;
			++i;
		}
		++i;
	}
  	cin.exceptions(ios::eofbit|ios::failbit);
  	Grid g(lev1, lev2, grph, sf1, sf2, seed);
  	string cmd;
  	bool seq = false;
  	ifstream file;
  	vector<string> coms;
 	g.nextBlock(1);
  	g.nextBlock(2);
  	cout << "\033c" << endl;
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
			g.moveBlock((pl%2)+1, coms[0], coms.size());
			int lev = g.getLevel((pl%2)+1);
			if (lev>=3) {
				g.moveBlock((pl%2)+1, "down", 1);
			}
			bool h = g.getHeavy((pl%2)+1);
			if ((h)&&(coms[0]!="down")) {
				g.moveBlock((pl%2)+1, "down", 2);
			}
	    		cout << g;
				cout  << "PLAYER " << (pl%2)+1 << "'S TURN"  << endl;
    		}
    		else if (coms[0]=="clockwise") {
	    		for (int i=0; i < coms.size(); i++) {
		    		g.rotateBlock((pl%2)+1, true);
	    		}
			int lev = g.getLevel((pl%2)+1);
                        if (lev>=3) {
                                g.moveBlock((pl%2)+1, "down", 1);
                        }
	    		cout << g;
				cout  << "PLAYER " << (pl%2)+1 << "'S TURN"  << endl;
    		}
    		else if (coms[0]=="counterclockwise") {
			for (int i=0; i < coms.size(); i++) {
				g.rotateBlock((pl%2)+1, false);
			}
			int lev = g.getLevel((pl%2)+1);
                        if (lev>=3) {
                                g.moveBlock((pl%2)+1, "down", 1);
                        }
			cout << g;
			cout  << "PLAYER " << (pl%2)+1 << "'S TURN"  << endl;
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
					cout << g;
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
			g.chngLevel((pl%2)+1, st, coms.size());
			cout << g;
                        cout  << "PLAYER " << (pl%2)+1 << "'S TURN"  << endl;
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
			if (!seq) {
				cin >> cmd;
			}
			file.open(cmd);
			seq = true;
		}
		else if (coms[0]=="restart") {
			g.restartGame(lev1, lev2);
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
  catch (...) {}
}

