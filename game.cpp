#include "game.hpp"

#include "globals.hpp"
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

Game::Game()
    : sprite(AnimatedSprite(graphics, "img.png",
                (SDL_Rect) {0, 48, 16, 16}, 160))
{}

Game::~Game() {}

void Game::run() {
    // XXX
    Point p1, p2, p3, p4, p5, p6;
    p1.x = 0;
    p2.x = 1;
    p3.x = 2;
    p4.x = 3;
    p5.x = 4;
    p6.x = 5;
    p1.y = 3;
    p2.y = 3;
    p3.y = 3;
    p4.y = 3;
    p5.y = 3;
    p6.y = 3;
    std::vector<Point> frames;
    frames.push_back(p1);
    frames.push_back(p2);
    frames.push_back(p3);
    frames.push_back(p4);
    frames.push_back(p5);
    frames.push_back(p6);

    sprite.addAnimation("run", frames);

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
        if (input.wasKeyPressed(SDL_SCANCODE_J)) sprite.runAnimation("run");
        if (input.wasKeyPressed(SDL_SCANCODE_K)) sprite.stopAnimation();

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
