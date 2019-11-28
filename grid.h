#ifndef GRID_H
#define GRID_H
#include "cell.h"
#include "textdisplay.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

class Cell;
class Piece;
class Level;
class TextDisplay;
class GraphicDisplay;

class Grid {
	//Display
	std::unique_ptr<GraphicDisplay> gd;
	std::unique_ptr<TextDisplay> td;
	//Player 1 Features
	std::vector<std::vector<std::unique_ptr<Cell>>> map1;
	std::vector<std::unique_ptr<Piece>> move1;
	std::unique_ptr<Level> lp1;
	int curscore1;
	int lev1;
	std::vector<std::vector<std::unique_ptr<Cell>>> nxtmap1;
	std::unique_ptr<Piece> nxtpc1;
	int uns1;
	bool bl1;
	bool hv1;
	std::string scf1;
	int highscore1;
	//Player 2 Features
	std::vector<std::vector<std::unique_ptr<Cell>>> map2;
	std::vector<std::unique_ptr<Piece>> move2;
	std::unique_ptr<Level> lp2;
	int curscore2;
	int lev2;
	std::vector<std::vector<std::unique_ptr<Cell>>> nxtmap2;
	std::unique_ptr<Piece> nxtpc2;
	int uns2;
	bool bl2;
	bool hv2;
	std::string scf2;
	int highscore2;
	//Randomness Tools
	int seed;
	private:
		Level* makeLevel(int n, int p);
	public:
		Grid(int l1=0, int l2=0, bool grph=true, std::string scf1="sequence1.txt", std::string scf2="sequence2.txt", int seed=0);
		void nextBlock(int p);
		void moveBlock(int p, std::string dir, int c);
		void rotateBlock(int p, bool clock);
		int dropBlock(int p);
		void chngLevel(int p, bool up, int c);
		void chngRandom(int p, std::string fl);
		int getLevel(int p);
		int getWinner();
		void bldPlay(int p);
		void forceNext(int p, std::string pc);
		bool getHeavy(int p);
		void setHeavy(int p, bool h);
		void restartGame(int l1=0, int l2=0);
		~Grid();
	friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
