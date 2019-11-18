#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

vector<string> autocommand(string s) {
	vector<string> coms = {"left", "right", "down", "clockwise", "counterclockwise", "drop", "levelup", "leveldown", "norandom", "random", "sequence", "restart"};
	int realcom = 0;
	for (int i=0; i<s.length(); i++) {
		if (!((s[i]=='0')||(s[i]=='1')||(s[i]=='2')||(s[i]=='3')||(s[i]=='4')||(s[i]=='5')||(s[i]=='6')||(s[i]=='7')||(s[i]=='8')||(s[i]=='9'))) {
			realcom = i;
			break;
		}
	}
	string actualcom = s.substr(realcom);
	int pos = 0;
	int max = 0;
	bool uniq = true;
	for (int i=0; i<coms.size(); i++) {
		int tempcount = 0;
		for (int j=0; j<coms[i].length(); j++) {
			if (actualcom[j]==coms[i][j]) {
				++tempcount;
			}
			else {
				break;
			}
		}
		if (tempcount > max) {
			max = tempcount;
			pos = i;
			uniq = true;
		}
		else if ((tempcount == max)&&(tempcount>0)) {
			uniq = false;
		}
	}
	if (!uniq) {
		throw invalid_argument("Command cannot be uniquely identified");
	}
	string num = s.substr(0, realcom);
	istringstream sock(num);
	int n;
	if (sock >> n) {
		vector<string> rep(n, coms[pos]);
		return rep;
	}
	else {
		vector<string> rep;
		rep.push_back(coms[pos]);
		return rep;
	}
}
