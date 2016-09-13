#ifndef game_hpp
#define game_hpp

#include "graphics.hpp"
#include "input.hpp"
#include "player.hpp"

class Game {
public:

    // Begins the game loop (begin accepting input and drawing to the window)
    void run();

private:
    void update(unsigned int elapsedTime);
    void draw();

    Graphics graphics;
    Input input;
};

#endif
