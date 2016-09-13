#include "graphics.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

Graphics::Graphics() {
    SDL_CreateWindowAndRenderer(1280, 720, 0, &window, &renderer);
    SDL_SetWindowTitle(window, "prototype");
    SDL_SetRenderDrawColor(renderer, 0x41, 0x65, 0x3c, SDL_ALPHA_OPAQUE);
}

Graphics::~Graphics() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

SDL_Texture *Graphics::createTexture(const std::string &path) {

    // Load the image as a surface if it does not exist
    if (surfaces.count(path) == 0) {
        surfaces[path] = IMG_Load(path.c_str());
    }

    // Load the image as a texture if it does not exist
    if (textures.count(path) == 0) {
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,
                surfaces[path]);
        unsigned int count = 1;
        std::pair<SDL_Texture *, unsigned int> pair (texture, count);

        textures[path] = pair;
    } else {
        SDL_Texture *texture = textures[path].first;
        unsigned int count = textures[path].second;

        std::pair<SDL_Texture *, unsigned int> pair (texture, count + 1);
        textures[path] = pair;
    }

    return textures[path].first;
}

void Graphics::freeTexture(const std::string &path) {
    if (textures.count(path) == 0) {
        std::cerr << "freeTexture failed: Invalid texture" << std::endl;
    } else {
        SDL_Texture *texture = textures[path].first;
        unsigned int count = textures[path].second;

        // Delete texture if this was called by last remaining user
        if (count == 1) {
            textures.erase(path);
            surfaces.erase(path);
        } else {
            std::pair<SDL_Texture *, unsigned int> pair (texture, count - 1);
            textures[path] = pair;
        }
    }
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
