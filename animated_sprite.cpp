#include "animated_sprite.hpp"

#include "graphics.hpp"
#include "sprite.hpp"
#include "vector.hpp"

#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <vector>

AnimatedSprite::AnimatedSprite() {
    std::clog << "AnimatedSprite instance successfully initialized\n";
}

AnimatedSprite::AnimatedSprite(Graphics &graphics, const std::string path,
        SDL_Rect sourceRect, unsigned int frameTime)
    : Sprite(graphics, path, sourceRect)
    , frameTime(frameTime)
    , timeSinceLastFrame(0)
    , animationIsRunning(false) {
    std::clog << "AnimatedSprite instance successfully initialized\n";
}

AnimatedSprite::~AnimatedSprite() {
    std::clog << "AnimatedSprite instance destroyed\n";
}

void AnimatedSprite::update(unsigned int elapsedTime) {
    timeSinceLastFrame += elapsedTime;

    if (timeSinceLastFrame >= frameTime) {
        timeSinceLastFrame = 0;

        if (animationIsRunning) advanceFrame();
    }
}

void AnimatedSprite::advanceFrame() {
    if (currentFrame == currentAnimation.size() - 1) {
        currentFrame = 0;
        
        animationIsRunning = false;
    } else {
        currentFrame++;
    }

    sourceRect.x = currentAnimation.at(currentFrame).x * sourceRect.w;
    sourceRect.y = currentAnimation.at(currentFrame).y * sourceRect.h;
}

void AnimatedSprite::addAnimation(std::string name,
        std::vector<Vector2<unsigned int> > frames) {
    animations[name] = frames;

    std::clog << "AnimatedSprite: Sprite animation added\n";
}

void AnimatedSprite::runAnimation(std::string name) {
    if (!animationIsRunning) {
        animationIsRunning = true;
        currentAnimation = animations[name];
        currentFrame = 0;
    }

    std::clog << "AnimatedSprite: Began running animation " << name << '\n';
}

void AnimatedSprite::stopAnimation() {
    animationIsRunning = false;

    // TODO Fix frame reset
    currentFrame = 0;
    sourceRect.x = currentAnimation.at(currentFrame).x * sourceRect.w;
    sourceRect.y = currentAnimation.at(currentFrame).y * sourceRect.h;

    std::clog << "AnimatedSprite: Stopped running current animation\n";
}
