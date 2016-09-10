#ifndef animated_sprite_hpp
#define animated_sprite_hpp

#include "sprite.hpp"

class AnimatedSprite : public Sprite {
public:
    AnimatedSprite();
    AnimatedSprite(Graphics &graphics, const std::string path,
            SDL_Rect sourceRect, unsigned int frameTime);

    void update(unsigned int elapsedTime);
private:
    unsigned int frameTime;
    unsigned int elapsedTime;

    void advanceFrame();
};

#endif
