#ifndef sprite_hpp
#define sprite_hpp

#include <string>
#include <SDL2/SDL.h>

class Sprite {
public:
    Sprite(const std::string, SDL_Rect src, SDL_Rect dst);

    void update();

    std::string path;

    SDL_Rect src;
    SDL_Rect dst;
};

#endif
