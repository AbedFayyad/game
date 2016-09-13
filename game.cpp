#include "game.hpp"

#include "graphics.hpp"
#include "input.hpp"
#include "vector.hpp"

#include <SDL2/SDL.h>
#include <iostream>
#include <string>

namespace {
    const unsigned int FPS = 60;
    const unsigned int MS_PER_S = 1000;
    const unsigned int MAX_FRAME_TIME = MS_PER_S / FPS; 
}

void Game::run() {
    bool shouldQuit = false;

    unsigned int currentTime, elapsedTime;
    unsigned int lastUpdateTime = SDL_GetTicks();

    while (!shouldQuit) {

        // Handle input events
        input.handleEvents();

        // Check if user requested to exit
        if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) shouldQuit = true;
        if (input.userRequestedShutdown) shouldQuit = true;

        // Calculate time since last update
        currentTime = SDL_GetTicks();
        elapsedTime = currentTime - lastUpdateTime;
        lastUpdateTime = currentTime;

        // Perform updates; cap frame time to the MAX_FRAME_TIME if necessary
        update(std::min(elapsedTime, MAX_FRAME_TIME));

        // Perform drawing
        draw();
    }
}

void Game::update(unsigned int elapsedTime) {}

void Game::draw() {
    graphics.clear();

    graphics.flip();
}
