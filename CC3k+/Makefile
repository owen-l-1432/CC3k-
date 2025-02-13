CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g
EXEC = cc3k
#SOURCES = $(wildcard *.cc)
#OBJECTS = ${SOURCES:.cc=.o}
OBJECTS = main.o cell.o character.o enemy.o floor.o item.o player.o floorgenerator.o potiongenerator.o seed.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}