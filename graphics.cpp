#include "graphics.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

Graphics::Graphics() {
    if (SDL_CreateWindowAndRenderer(1280, 720, 0, &window, &renderer))
        std::cerr << "SDL_CreateWindowAndRenderer failed: " << SDL_GetError();

    SDL_SetWindowTitle(window, "prototype");
    if (SDL_SetRenderDrawColor(renderer, 0x41, 0x65, 0x3c, SDL_ALPHA_OPAQUE))
        std::cerr << "SDL_SetRenderDrawColor failed: " << SDL_GetError();

    std::clog << "Graphics instance successfully initialized\n";
}

Graphics::~Graphics() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    std::clog << "Graphics instance destroyed\n";
}

SDL_Texture *Graphics::createTexture(const std::string &path) {

    // Load the image as a surface if it does not exist
    if (surfaces.count(path) == 0) {
        SDL_Surface *surface = IMG_Load(path.c_str());
        if (!surface) {
            std::cerr << "IMG_Load failed to load " << path;
            return NULL;
        }

        surfaces[path] = surface;
    }

    // Load the image as a texture if it does not exist
    if (textures.count(path) == 0) {
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer,
                surfaces[path]);
        if (!texture) {
            std::cerr << "SDL_CreateTextureFromSurface failed: "
                << SDL_GetError();
            return NULL;
        }

        unsigned int count = 1;
        std::pair<SDL_Texture *, unsigned int> pair (texture, count);

        textures[path] = pair;
    } else {
        SDL_Texture *texture = textures[path].first;
        unsigned int count = textures[path].second;

        std::pair<SDL_Texture *, unsigned int> pair (texture, count + 1);
        textures[path] = pair;
    }

    std::clog << "Graphics: Created texture from " << path << '\n';

    return textures[path].first;
}

void Graphics::freeTexture(const std::string &path) {
    if (textures.count(path) == 0) {
        std::cerr << "freeTexture failed: Invalid texture " << path;
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

    std::clog << "Graphics: Freed texture " << path << '\n';
}

void Graphics::draw(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dest) {
    if (SDL_RenderCopy(renderer, texture, src, dest))
        std::cerr << "SDL_RenderCopy failed: " << SDL_GetError();
}

void Graphics::flip() {
    SDL_RenderPresent(renderer);
}

void Graphics::clear() {
    if (SDL_RenderClear(renderer))
        std::cerr << "SDL_RenderClear failed: " << SDL_GetError();
}
