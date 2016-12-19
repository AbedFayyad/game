CC=clang++
EXE=game
OBJS=game.o main.o
FLAGS=-g -Wall -F/Library/Frameworks/
FRAMEWORKS=-framework SDL2 -framework SDL2_image

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(FLAGS) $(FRAMEWORKS)

game.o: game.cpp
	$(CC) -c game.cpp $(FLAGS)

main.o: main.cpp
	$(CC) -c main.cpp $(FLAGS)

clean:
	rm -f $(EXE) $(OBJS)
