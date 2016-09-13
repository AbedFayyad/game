#include "input.hpp"

#include <SDL2/SDL.h>
#include <iostream>

Input::Input() : userRequestedShutdown(false) {}

void Input::handleEvents() {
    resetEvents();

    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            userRequestedShutdown = true;
            break;
        case SDL_KEYDOWN:
            if (!event.key.repeat) keyDownEvent(event);
            break;
        case SDL_KEYUP:
            keyUpEvent(event);
            break;
        }
    }
}

void Input::resetEvents() {
    pressedKeys.clear();
    releasedKeys.clear();
}


void Input::keyDownEvent(const SDL_Event &event) {
    pressedKeys[event.key.keysym.scancode] = true;
    heldKeys[event.key.keysym.scancode] = true;
}

void Input::keyUpEvent(const SDL_Event &event) {
    releasedKeys[event.key.keysym.scancode] = true;
    heldKeys[event.key.keysym.scancode] = false;
}


bool Input::wasKeyPressed(SDL_Scancode key) {
    return pressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key) {
    return releasedKeys[key];
}

bool Input::isKeyHeld(SDL_Scancode key) {
    return heldKeys[key];
}
