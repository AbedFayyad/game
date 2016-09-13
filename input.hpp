#ifndef input_hpp
#define input_hpp

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

    void resetEvents();
    void keyDownEvent(const SDL_Event &event);
    void keyUpEvent(const SDL_Event &event);
};

#endif
