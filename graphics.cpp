#include "graphics.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <utility>

Graphics::Graphics() {
    SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);
    SDL_SetWindowTitle(window, "prototype");
}

Graphics::~Graphics() {
    // TODO Unload all surfaces and textures

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

SDL_Texture *loadImage(const std::string &path) {

    // Load surface if it does not exist
    if (surfaces.count(path) == 0) {
        surfaces[path] = IMG_Load(path.c_str());
    }

    // Create texture from surface if it does not exist
    if (textures.count(path) == 0) {
        std::pair<SDL_Surface *, unsigned int>
        textures[path] = std::make_pair
    }
}

void unloadImage(const std::string &path) {
}

/*
SDL_Surface *Graphics::loadImage(const std::string &path) {
    if (spriteSheets.count(path) == 0) {
        spriteSheets[path] = IMG_Load(path.c_str());
    }

    return spriteSheets[path];
}
*/

void Graphics::draw(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dest) {
    SDL_RenderCopy(renderer, texture, src, dest);
}

void Graphics::flip() {
    SDL_RenderPresent(renderer);
}

void Graphics::clear() {
    SDL_RenderClear(renderer);
}
