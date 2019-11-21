CXX=g++
CXXFLAGS=-std=c++14 -Wall -Werror=vla -MMD -g
OBJECTS=autocommand.o main.o grid.o cell.o piece.o pieceI.o pieceZ.o pieceS.o pieceT.o pieceO.o pieceJ.o level0.o level1.o
DEPS=${OBJECTS:.o=.d}
EXEC=biquadris

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPS}

.PHONY: clean
clean:
	rm ${OBJECTS} ${EXEC} ${DEPS}
