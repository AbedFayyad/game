#include "game.hpp"

#include "graphics.hpp"
#include "input.hpp"
#include "animated_sprite.hpp"

#include <SDL2/SDL.h>
#include <iostream>
#include <string>

namespace {
    const unsigned int FPS = 60;
    const unsigned int MS_PER_S = 1000;
    const unsigned int MAX_FRAME_TIME = MS_PER_S / FPS; 
}

Game::Game() : sprite(AnimatedSprite(graphics, "img.png",
            (SDL_Rect) {0, 48, 16, 16}, 160)) {}

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
    sprite.update(elapsedTime);
}

void Game::draw() {
    graphics.clear();

    sprite.draw(100, 100);

    graphics.flip();
}
