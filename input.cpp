#include "input.hpp"

#include <SDL2/SDL.h>
#include <iostream>

Input::Input() : userRequestedShutdown(false) {}

void Input::handleEvents() {
    resetEvents();

    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT: userRequestedShutdown = true; break;

        case SDL_KEYDOWN: if (!event.key.repeat) keyDownEvent(event.key); break;
        case SDL_KEYUP: keyUpEvent(event.key); break;

        // TODO Handle unplugged/new controllers
        case SDL_CONTROLLERDEVICEADDED: break;
        case SDL_CONTROLLERDEVICEREMOVED: break;

        case SDL_CONTROLLERBUTTONDOWN: buttonDownEvent(event.cbutton); break;
        case SDL_CONTROLLERBUTTONUP: buttonUpEvent(event.cbutton); break;

        case SDL_CONTROLLERAXISMOTION: axisMotionEvent(event.caxis); break;
        }
    }
}

void Input::resetEvents() {
    pressedKeys.clear();
    releasedKeys.clear();

    pressedButtons.clear();
    releasedButtons.clear();

    // TODO Should (continuous) value be reset between frames?
    leftAxis.x = 0; leftAxis.y = 0;
    rightAxis.x = 0; rightAxis.y = 0;
    leftTrigger = 0; rightTrigger = 0;
}


void Input::keyDownEvent(const SDL_KeyboardEvent &event) {
    pressedKeys[event.keysym.scancode] = true;
    heldKeys[event.keysym.scancode] = true;
}

void Input::keyUpEvent(const SDL_KeyboardEvent &event) {
    releasedKeys[event.keysym.scancode] = true;
    heldKeys[event.keysym.scancode] = false;
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

void Input::buttonDownEvent(const SDL_ControllerButtonEvent &event) {
    pressedButtons[event.button] = true;
    heldButtons[event.button] = true;
    std::cout << "down" << std::endl;
}

void Input::buttonUpEvent(const SDL_ControllerButtonEvent &event) {
    releasedButtons[event.button] = true;
    heldButtons[event.button] = false;
    std::cout << "up" << std::endl;
}

void Input::axisMotionEvent(const SDL_ControllerAxisEvent &event) {
    switch (event.axis) {
    case SDL_CONTROLLER_AXIS_LEFTX: leftAxis.x = event.value; break;
    case SDL_CONTROLLER_AXIS_LEFTY: leftAxis.y = event.value; break;
    case SDL_CONTROLLER_AXIS_RIGHTX: rightAxis.x = event.value; break;
    case SDL_CONTROLLER_AXIS_RIGHTY: rightAxis.y = event.value; break;
    case SDL_CONTROLLER_AXIS_TRIGGERLEFT: leftTrigger = event.value; break;
    case SDL_CONTROLLER_AXIS_TRIGGERRIGHT: rightTrigger = event.value; break;
    }
}
