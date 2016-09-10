#ifndef input_hpp
#define input_hpp

#include <SDL2/SDL.h>
#include <map>

class Input {
public:

    // Called at the begnning of each frame to reset pressed and released keys
    void beginNewFrame();


    // Called when a key is pressed
    void keyDownEvent(const SDL_Event &event);

    // Called when a key is released
    void keyUpEvent(const SDL_Event &event);


    // Check if a key was pressed during the current frame
    bool wasKeyPressed(SDL_Scancode key);

    // Check if a key was released during the current frame
    bool wasKeyReleased(SDL_Scancode key);

    // Check if a key is being held during the current frame
    bool isKeyHeld(SDL_Scancode key);

private:

    // Maps to keep track of the current frame's relevant keystrokes
    std::map<SDL_Scancode, bool> heldKeys;
    std::map<SDL_Scancode, bool> pressedKeys;
    std::map<SDL_Scancode, bool> releasedKeys;
};

#endif
