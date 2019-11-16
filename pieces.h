#ifndef PIECE_H
#define PIECE_H

class Cell;

class Piece {
	protected:
		char disp;
		int valid;
		Cell *p1;
		Cell *p2;
		Cell *p3;
		Cell *p4;
	public:
		void move(std::string dir);
		void rotate(bool cl);
		void drop();
		virtual ~Piece() = 0;
}
