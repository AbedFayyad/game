#include "sprite.hpp"

#include "graphics.hpp"

#include <SDL2/SDL.h>
#include <iostream>
#include <string>

Sprite::Sprite() {
    std::clog << "Sprite instance successfully initialized\n";
}

Sprite::Sprite(Graphics &graphics, const std::string path, SDL_Rect sourceRect)
    : graphics(&graphics)
    , sourceRect(sourceRect)
    , spriteSheet(graphics.createTexture(path))
    , spriteSheetPath(path) {
    std::clog << "Sprite instance successfully initialized\n";
}

Sprite::~Sprite() {
    graphics->freeTexture(spriteSheetPath);

    std::clog << "Sprite instance destroyed\n";
}

void Sprite::update() {}

void Sprite::draw(int x, int y) {
    SDL_Rect destinationRect = {x, y, sourceRect.w * 8, sourceRect.h * 8};

    graphics->draw(spriteSheet, &sourceRect, &destinationRect);
}
