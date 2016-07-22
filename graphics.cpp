#include "graphics.hpp"

// OpenGL includes go here
#include <SDL2/SDL.h>

Graphics::Graphics() {

    // Set OpenGL attributes
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // Create a window
    window = SDL_CreateWindow("game",
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              640, 480,
                              SDL_WINDOW_OPENGL);
    if (!window) {
        fprintf(stderr, "SDL_CreateWindow failed %s\n", SDL_GetError());
    }

    // Create an OpenGL context
    glcontext = SDL_GL_CreateContext(window);
    if (!glcontext) {
        fprintf(stderr, "SDL_GL_CreateContext failed %s\n", SDL_GetError());
    }

    // TODO: The rest of the OpenGL stuff
}

Graphics::~Graphics() {

    // TODO: Clear OpenGL things

    SDL_DestroyWindow(window);

    SDL_GL_DeleteContext(glcontext);
}

void Graphics::draw() {
    
    // TODO: Do OpenGL drawing

    SDL_GL_SwapWindow(window);
}
