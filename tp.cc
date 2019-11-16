#include "grid.h"
#include "cell.h"
#include <iostream>
using namespace std;

int main() {
	Grid g;
	cout << g;
	g.nextBlock(1);
	cout << g;
}
