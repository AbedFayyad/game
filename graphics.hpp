#ifndef graphics_hpp
#define graphics_hpp

#include <SDL2/SDL.h>
#include <map>
#include <string>

class Graphics {
public:
    Graphics();
    ~Graphics();

    // Create a texture from the given image; return NULL on error
    SDL_Texture *createTexture(const std::string &path);

    // Delete a texture when it is no longer needed
    void freeTexture(const std::string &path);

    // Draw a texture to the screen
    void draw(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dest);

    // Present the contents of the renderer's backbuffer
    void flip();

    // Clear the screen - should be called before every frame is drawn
    void clear();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    // TODO Consider removing surfaces immediately after texture is created
    // Map to keep track of surfaces
    std::map<std::string, SDL_Surface *> surfaces;

    // Map to keep track of textures and number of remaining users
    std::map<std::string, std::pair<SDL_Texture *, unsigned int> > textures;
};

#endif
