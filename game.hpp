#ifndef game_hpp
#define game_hpp

#include "graphics.hpp"
#include "input.hpp"
#include "animated_sprite.hpp"

class Game {
public:
    Game();
    ~Game();

    // Begins the game loop (begin accepting input and drawing to the window)
    void run();

private:
    void update(unsigned int elapsedTime);
    void draw();

    Graphics graphics;
    Input input;
    AnimatedSprite sprite;
};

#endif
