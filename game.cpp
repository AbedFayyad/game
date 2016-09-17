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

Game::Game() : activeScene(NULL) {

    // Set up SDL flags
    Uint32 flags = SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER;

    // Initialize SDL subsystems and start game if successful
    if (!SDL_Init(flags)) {
        std::clog << "Game instance successfully initialized\n";
        gameLoop();
    } else std::cerr << "SDL_Init failed: " << SDL_GetError() << '\n';
}

Game::~Game() {

    // Clean up SDL subsystems (regardless of initialization)
    SDL_Quit();

    std::clog << "Game instance destroyed\n";
}

void Game::gameLoop() {
    std::clog << "Game: Game loop began\n";

    Graphics graphics;
    Input input;

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
        draw(graphics);
    }

    std::clog << "Game: Game loop ended\n";
}

void Game::addScene(const std::string name, Scene scene) {}

void Game::setActiveScene(const std::string name) {}

void Game::update(unsigned int elapsedTime) {
    activeScene->update(elapsedTime);
}

void Game::draw(Graphics &graphics) {
    graphics.clear();

    activeScene->draw(graphics);

    graphics.flip();
}
