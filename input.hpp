#ifndef input_hpp
#define input_hpp

#include "vector.hpp"

#include <SDL2/SDL.h>
#include <map>

class Input {
public:
    Input();

    bool userRequestedShutdown;

    void handleEvents();

    // Check if a key was pressed during the current frame
    bool wasKeyPressed(SDL_Scancode key);

    // Check if a key was released during the current frame
    bool wasKeyReleased(SDL_Scancode key);

    // Check if a key is being held during the current frame
    bool isKeyHeld(SDL_Scancode key);

private:
    std::map<SDL_Scancode, bool> heldKeys;
    std::map<SDL_Scancode, bool> pressedKeys;
    std::map<SDL_Scancode, bool> releasedKeys;

    // Uint8 holds a member of the SDL_GameControllerButton enum
    std::map<Uint8, bool> heldButtons;
    std::map<Uint8, bool> pressedButtons;
    std::map<Uint8, bool> releasedButtons;
    Vector2<Sint16> leftAxis;
    Vector2<Sint16> rightAxis;
    Sint16 leftTrigger;
    Sint16 rightTrigger;

    void resetEvents();
    void keyDownEvent(const SDL_KeyboardEvent &event);
    void keyUpEvent(const SDL_KeyboardEvent &event);

    void buttonDownEvent(const SDL_ControllerButtonEvent &event);
    void buttonUpEvent(const SDL_ControllerButtonEvent &event);
    void axisMotionEvent(const SDL_ControllerAxisEvent &event);
};

#endif
