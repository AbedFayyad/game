CC=g++
EXE=game
FLAGS=-g -Wall
LIBS=-lSDL2 -lSDL2_image
SRCS=$(wildcard *.cpp)
#OBJS=$(addsuffix .o, $(basename $(SRCS)))
OBJS=main.o game.o graphics.o input.o sprite.o animated_sprite.o vector.o

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(FLAGS) $(LIBS)

%.o: %.cpp
	$(CC) -c $< $(FLAGS) $(LIBS)

clean:
	rm -rf $(EXE) $(OBJS)
