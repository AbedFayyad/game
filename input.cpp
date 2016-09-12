#include "input.hpp"

#include <SDL2/SDL.h>
#include <iostream>

Input::Input() {
    int numJoysticks = SDL_NumJoysticks();
    std::cout << "Input: Detected " << numJoysticks << " joystick"
        << (numJoysticks == 1 ? "." : "s.") << std::endl;

    for (int i = 0; i < numJoysticks; ++ i) {
        if (SDL_IsGameController(i)) {
            controller = SDL_GameControllerOpen(i);
            break;
        }
    }
}

void Input::printInfo() {
    if (!controller) return;

    std::cout << "Input: Left trigger's value is "
        << SDL_GameControllerGetAxis(controller,
                SDL_CONTROLLER_AXIS_TRIGGERLEFT) << std::endl;
}

void Input::beginNewFrame() {
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
