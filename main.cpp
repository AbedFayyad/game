#include "game.hpp"

#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char *argv[]) {

    // Set up SDL flags
    Uint32 flags = SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER;

    // Initialize SDL subsystems and start game if successful
    if (!SDL_Init(flags)) {

        // Must be kept in inner scope so destructor is called before SDL quits
        Game game;
        game.run();
    } else std::cerr << "SDL_Init failed: " << SDL_GetError() << std::endl;


    // Clean up SDL subsystems (regardless of initialization)
    SDL_Quit();

    return 0;
}
