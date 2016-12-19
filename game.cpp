#include "game.hpp"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

using std::cerr;
using std::endl;

Game::Game() {

    /* Initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO))
        cerr << "SDL_Init: " << SDL_GetError() << endl;

    /* Set up SDL_Window and SDL_Renderer */
    if (SDL_CreateWindowAndRenderer(1280, 768, 0, &window, &renderer))
        cerr << "SDL_CreateWindowAndRenderer: " << SDL_GetError() << endl;

    SDL_SetWindowTitle(window, "game");

    /* Begin main game loop */
    run();
}

Game::~Game() {

    /* Destroy window */
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    /* Shut down SDL */
    SDL_Quit();
}

void Game::run() {
    SDL_Event event;
    bool shouldQuit = false;
    unsigned int currentTime, elapsedTime;
    unsigned int lastUpdateTime = SDL_GetTicks();

    while (!shouldQuit) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    shouldQuit = true;
                    break;

                case SDL_KEYDOWN:
                    if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                        shouldQuit = true;
                    break;

                default:
                    break;
            }
        }

        /* Delta timing */
        currentTime = SDL_GetTicks();
        elapsedTime = currentTime - lastUpdateTime;
        lastUpdateTime = currentTime;

        /* Perform updates */
        update(elapsedTime);

        /* Perform drawing */
        clear();

        SDL_Rect src = {64 * 5, 0, 64, 64};
        SDL_Rect dst = {0, 0, 64, 64};
        std::string path("content/sprites/sheet.png");
        for (int i = 0; i < 20; ++i) {
            for (int j = 0; j < 12; ++j) {
                dst.x = i * 64;
                dst.y = j * 64;
                draw(path, &src, &dst);
            }
        }

        flip();
    }
}

void Game::update(const unsigned int elapsedTime) {
}

void Game::draw(const std::string &path, const SDL_Rect *src,
                                         const SDL_Rect *dst) {

    /* Create texture from path if it does not exist */
    if (textures.count(path) == 0) {
        SDL_Surface *surface;
        SDL_Texture *texture;

        if (!(surface = IMG_Load(path.c_str())))
            cerr << "IMG_Load: " << IMG_GetError() << endl;

        if (!(texture = SDL_CreateTextureFromSurface(renderer, surface)))
            cerr << "SDL_CreateTextureFromSurface: " << SDL_GetError() << endl;

        textures[path] = texture;
        SDL_FreeSurface(surface);
    }

    /* Look up texture from texture map */
    SDL_Texture *texture = textures[path];

    if (SDL_RenderCopy(renderer, texture, src, dst))
        cerr << "SDL_RenderCopy: " << SDL_GetError() << endl;
}

void Game::flip() {
    SDL_RenderPresent(renderer);
}

void Game::clear() {
    if (SDL_RenderClear(renderer))
        cerr << "SDL_RenderClear: " << SDL_GetError() << endl;
}
