#ifndef sprite_hpp
#define sprite_hpp

#include <SDL2/SDL.h>
#include <string>

class Graphics;

class Sprite {
public:
    Sprite();
    Sprite(Graphics &graphics, const std::string path, SDL_Rect sourceRect);
    ~Sprite();

    void update();
    void draw(Graphics &graphics, int x, int y);
private:
    SDL_Rect sourceRect;
    SDL_Texture *spriteSheet;
};

#endif
