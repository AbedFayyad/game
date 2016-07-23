CC=g++
OBJS=main.o game.o graphics.o input.o shader.o
EXE=game
FLAGS=-Wall
LIBS=-lSDL2 -lGL

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(FLAGS) $(LIBS)

main.o: main.cpp game.hpp
	$(CC) -c main.cpp $(LIBS)
game.o: game.cpp graphics.hpp input.hpp
	$(CC) -c game.cpp $(LIBS)
graphics.o: graphics.cpp $(LIBS)
	$(CC) -c graphics.cpp $(LIBS)
input.o: input.cpp $(LIBS)
	$(CC) -c input.cpp $(LIBS)
shader.o: shader.cpp $(LIBS)
	$(CC) -c shader.cpp $(LIBS)

clean:
	rm -rf $(EXE) $(OBJS)
