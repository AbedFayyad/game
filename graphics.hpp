#ifndef graphics_hpp
#define graphics_hpp

#include <SDL2/SDL.h>
#include <map>
#include <string>
#include <utility>

class Graphics {
public:
    Graphics();
    ~Graphics();

    // Load an image into memory
    SDL_Texture *loadImage(const std::string &path);

    // Unload an image from memory
    void unloadImage(const std::string &path);

    // Draw a texture to the screen
    void draw(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dest);

    // Present the contents of the renderer's backbuffer
    void flip();

    // Clear the screen - should be called before every frame is drawn
    void clear();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    std::map<std::string, SDL_Surface *> surfaces;
    std::map<std::string, std::pair<SDL_Surface *, unsigned int> > textures;
};

#endif
