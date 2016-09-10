#include "sprite.hpp"

#include "graphics.hpp"

#include <SDL2/SDL.h>
#include <iostream>

Sprite::Sprite() {}

Sprite::Sprite(Graphics &graphics, const std::string path, SDL_Rect sourceRect)
    : sourceRect(sourceRect) {
    spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(),
            graphics.loadImage(path));

    if (!spriteSheet) {
        std::cerr << "SDL_CreateTextureFromSurface failed: " << SDL_GetError()
            << std::endl;
    }
}

Sprite::~Sprite() {
    SDL_DestroyTexture(spriteSheet);
}

void Sprite::update() {}

void Sprite::draw(Graphics &graphics, int x, int y) {
    SDL_Rect destinationRect = {x, y, sourceRect.w * 16, sourceRect.h * 16};

    graphics.draw(spriteSheet, &sourceRect, &destinationRect);
}
