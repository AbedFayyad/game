#ifndef game_hpp
#define game_hpp

#include "graphics.hpp"

class Game {
public:
    Game();
    ~Game();

private:
    void gameLoop();

    void update(unsigned int elapsedTime);
    void draw(Graphics &graphics);
};

#endif
