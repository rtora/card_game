CXX = g++
CXXFLAGS= -std=c++11 -g

game: cards.o main.o
	${CXX} -o $@ $^
	
unittest: cards.o tests.o
	${CXX} -o $@ $^
	
clean:
			/bin/rm -f game unittest *.o
