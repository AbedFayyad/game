#include "sprite.hpp"

#include "graphics.hpp"

#include <SDL2/SDL.h>
#include <iostream>
#include <string>

Sprite::Sprite() {}

Sprite::Sprite(Graphics &graphics, const std::string path, SDL_Rect sourceRect)
    : graphics(&graphics)
    , sourceRect(sourceRect)
    , spriteSheet(graphics.createTexture(path))
    , spriteSheetPath(path) {}

Sprite::~Sprite() {
    graphics->deleteTexture(spriteSheetPath);
}

void Sprite::update() {}

void Sprite::draw(int x, int y) {
    SDL_Rect destinationRect = {x, y, sourceRect.w * 32, sourceRect.h * 32};

    graphics->draw(spriteSheet, &sourceRect, &destinationRect);
}
