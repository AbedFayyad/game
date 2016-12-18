CC=clang++
EXE=game
FLAGS=-g -Wall -F/Library/Frameworks/
FRAMEWORKS=-framework SDL2 -framework SDL2_image
SRCS=$(wildcard *.cpp)
#OBJS=$(addsuffix .o, $(basename $(SRCS)))
OBJS=main.o game.o graphics.o input.o sprite.o animated_sprite.o scene.o entity.o

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(FLAGS) $(FRAMEWORKS)

%.o: %.cpp
	$(CC) -c $< $(FLAGS)

clean:
	rm -rf $(EXE) $(OBJS)
