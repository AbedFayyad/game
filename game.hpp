#ifndef game_hpp
#define game_hpp

#include <map>
#include <string>
#include <SDL2/SDL.h>
#include "sprite.hpp"

class Game {
public:
    Game();
    ~Game();

    /* Begin the game's main loop */
    void run();

    /* Perform updates – should be called before every frame is drawn */
    void update(const unsigned int);

    /* Draw a texture to the screen */
    void draw(const std::string &, const SDL_Rect *, const SDL_Rect *);

    /* Draw a sprite to the screen */
    void draw(const Sprite &);

    /* Present the contents of the renderer's backbuffer */
    void flip();

    /* Clear the screen – should be called before every frame is drawn */
    void clear();

    /* Return whether or not the given key is being held in the current frame */
    bool isKeyHeld(SDL_Scancode);

    /* Return whether or not the given key was pressed in the current frame */
    bool wasKeyPressed(SDL_Scancode);

    /* Return whether or not the given key was released in the current frame */
    bool wasKeyReleased(SDL_Scancode);
private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    std::map<std::string, SDL_Texture *> textures;

    std::map<SDL_Scancode, bool> heldKeys;
    std::map<SDL_Scancode, bool> pressedKeys;
    std::map<SDL_Scancode, bool> releasedKeys;
};

#endif
