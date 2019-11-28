CXX=g++
CXXFLAGS=-std=c++14 -MMD -g
OBJECTS=autocommand.o main.o grid.o cell.o piece.o pieceI.o pieceZ.o pieceS.o pieceT.o pieceO.o pieceJ.o pieceStar.o pieceL.o level0.o level1.o level2.o level3.o level4.o subject.o textdisplay.o window.o graphicdisplay.o
DEPS=${OBJECTS:.o=.d}
EXEC=biquadris

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -lX11 -o ${EXEC}

-include ${DEPS}

.PHONY: clean
clean:
	rm ${OBJECTS} ${DEPS}
