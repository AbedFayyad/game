CC=clang++
EXE=game
OBJS=game.o main.o
FLAGS=-g -Wall -F/Library/Frameworks/
FRAMEWORKS=-framework SDL2 -framework SDL2_image

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(FLAGS) $(FRAMEWORKS)

%.o: %.cpp
	$(CC) -c $< $(FLAGS)

clean:
	rm -f $(EXE) $(OBJS)
