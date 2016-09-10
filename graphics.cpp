#include "graphics.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

Graphics::Graphics() {
    SDL_CreateWindowAndRenderer(1280, 720, 0, &window, &renderer);
    SDL_SetWindowTitle(window, "prototype");
}

Graphics::~Graphics() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

SDL_Renderer *Graphics::getRenderer() const {
    return renderer;
}

SDL_Surface *Graphics::loadImage(const std::string &path) {
    if (spriteSheets.count(path) == 0) {
        spriteSheets[path] = IMG_Load(path.c_str());
    }

    return spriteSheets[path];
}

void Graphics::draw(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dest) {
    SDL_RenderCopy(renderer, texture, src, dest);
}

void Graphics::flip() {
    SDL_RenderPresent(renderer);
}

void Graphics::clear() {
    SDL_RenderClear(renderer);
}
