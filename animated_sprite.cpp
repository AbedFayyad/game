#include "animated_sprite.hpp"

AnimatedSprite::AnimatedSprite() {}

AnimatedSprite::AnimatedSprite(Graphics &graphics, const std::string path,
        SDL_Rect sourceRect, unsigned int frameTime)
    : Sprite(graphics, path, sourceRect)
    , frameTime(frameTime)
    , elapsedTime(0) {}

void AnimatedSprite::update(unsigned int elapsedTime) {
    this->elapsedTime += elapsedTime;

    if (this->elapsedTime >= frameTime) {
        this->elapsedTime = 0;
        advanceFrame();
    }
}

void AnimatedSprite::advanceFrame() {
    sourceRect.x += 16;
    if (sourceRect.x > (16 * 5)) sourceRect.x = 0;
}
