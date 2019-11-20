biquadris: autocommand.o main.o grid.o cell.o piece.o pieceI.o pieceZ.o pieceS.o pieceT.o pieceO.o level0.o level1.o
	g++ autocommand.o main.o grid.o cell.o piece.o pieceI.o pieceZ.o pieceS.o pieceT.o pieceO.o level0.o level1.o -o biquadris
autocommand.o: autocommand.cc autocommand.h grid.h cell.h piece.h pieceI.h pieceZ.h pieceS.h pieceT.h pieceO.h level0.h level.h level1.h
	g++ -c autocommand.cc
main.o: main.cc autocommand.h grid.h cell.h piece.h pieceI.h pieceZ.h pieceS.h pieceT.h pieceO.h level0.h level.h level1.h
	g++ -c main.cc
grid.o: grid.cc autocommand.h grid.h cell.h piece.h pieceI.h pieceZ.h pieceS.h pieceT.h pieceO.h level0.h level.h level1.h
	g++ -c grid.cc
cell.o: cell.cc autocommand.h grid.h cell.h piece.h pieceI.h pieceZ.h pieceS.h pieceT.h pieceO.h level0.h level.h level1.h
	g++ -c cell.cc
piece.o: piece.cc autocommand.h grid.h cell.h piece.h pieceI.h pieceZ.h pieceS.h pieceT.h pieceO.h level0.h level.h level1.h
	g++ -c piece.cc
pieceI.o: pieceI.cc autocommand.h grid.h cell.h piece.h pieceI.h pieceZ.h pieceS.h pieceT.h pieceO.h level0.h level.h level1.h
	g++ -c pieceI.cc
pieceZ.o: pieceZ.cc autocommand.h grid.h cell.h piece.h pieceI.h pieceZ.h pieceS.h pieceT.h pieceO.h level0.h level.h level1.h
	g++ -c pieceZ.cc
pieceS.o: pieceS.cc autocommand.h grid.h cell.h piece.h pieceI.h pieceZ.h pieceS.h pieceT.h pieceO.h level0.h level.h level1.h
	g++ -c pieceS.cc
pieceT.o: pieceT.cc autocommand.h grid.h cell.h piece.h pieceI.h pieceZ.h pieceS.h pieceT.h pieceO.h level0.h level.h level1.h
	g++ -c pieceT.cc
pieceO.o: pieceO.cc autocommand.h grid.h cell.h piece.h pieceI.h pieceZ.h pieceS.h pieceT.h pieceO.h level0.h level.h level1.h
	g++ -c pieceO.cc
level0.o: level0.cc autocommand.h grid.h cell.h piece.h pieceI.h pieceZ.h pieceS.h pieceT.h pieceO.h level0.h level.h level1.h
	g++ -c level0.cc
level1.o: level1.cc autocommand.h grid.h cell.h piece.h pieceI.h pieceZ.h pieceS.h pieceT.h pieceO.h level0.h level.h level1.h
	g++ -c level1.cc
