#include "game.hpp"

#include "globals.hpp"
#include "graphics.hpp"
#include "input.hpp"
#include "player.hpp"

#include <SDL2/SDL.h>
#include <iostream>
#include <string>

namespace {
    const unsigned int FPS = 60;
    const unsigned int MS_PER_S = 1000;
    const unsigned int MAX_FRAME_TIME = MS_PER_S / FPS; 
}

Game::Game() : player(graphics, (Point<float>) {0, 0})
{}

Game::~Game() {}

void Game::run() {
    unsigned int lastUpdateTime, currentTime, elapsedTime;

    bool shouldQuit = false;
    SDL_Event event;

    lastUpdateTime = SDL_GetTicks();

    while (!shouldQuit) {

        // Inform Input object of new frame
        input.beginNewFrame();

        // Handle events
        if (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_KEYDOWN:
                    if (!event.key.repeat) input.keyDownEvent(event);
                    break;
                case SDL_KEYUP:
                    input.keyUpEvent(event);
                    break;
                case SDL_QUIT:
                    shouldQuit = true;
                    break;
            }
        }

        // Exit if requested
        if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) shouldQuit = true;

        if (input.isKeyHeld(SDL_SCANCODE_D)) player.moveRight();
        if (input.wasKeyReleased(SDL_SCANCODE_D)) player.stopMoving();

        currentTime = SDL_GetTicks();
        elapsedTime = currentTime - lastUpdateTime;
        lastUpdateTime = currentTime;

        // Perform updates; cap frame time to the MAX_FRAME_TIME if necessary
        update(std::min(elapsedTime, MAX_FRAME_TIME));

        // Perform drawing
        draw();
    }
}

void Game::update(unsigned int elapsedTime) {
    player.update(elapsedTime);
}

void Game::draw() {
    graphics.clear();

    player.draw();

    graphics.flip();
}
