#include "game.hpp"

#include "graphics.hpp"
#include "input.hpp"
#include "sprite.hpp"

#include <SDL2/SDL.h>
#include <iostream>
#include <string>

namespace {
    const unsigned int FPS = 60;
    const unsigned int MAX_FRAME_TIME = 6 * 1000 / FPS;
}

Game::Game() : sprite(Sprite(graphics, "img.png", (SDL_Rect) {0, 0, 16, 16})) {}

Game::~Game() {}

void Game::run() {
    bool shouldQuit = false;
    SDL_Event event;

    unsigned int lastUpdateTime = SDL_GetTicks();

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

        // Cap frame time to the MAX_FRAME_TIME if necessary
        unsigned int elapsedTime = SDL_GetTicks() - lastUpdateTime;

        // Perform updates
        update(std::min(elapsedTime, MAX_FRAME_TIME));

        // Perform drawing
        draw();
        graphics.clear();

        sprite.draw(graphics, 0, 0);

        graphics.flip();
    }
}

void Game::update(unsigned int elapsedTime) {}

void Game::draw() {}
