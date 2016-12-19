#ifndef game_hpp
#define game_hpp

#include <map>
#include <string>
#include <SDL2/SDL.h>

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

    /* Present the contents of the renderer's backbuffer */
    void flip();

    /* Clear the screen – should be called before every frame is drawn */
    void clear();
private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    std::map<std::string, SDL_Texture *> textures;
};

#endif
