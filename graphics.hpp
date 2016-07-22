#ifndef graphics_hpp
#define graphics_hpp

struct SDL_Window;
typedef void *SDL_GLContext;
typedef unsigned int uint32_t;
typedef uint32_t GLuint;

class Graphics {
public:
    Graphics();
    ~Graphics();

    void draw();
private:
    SDL_Window *window;
    SDL_GLContext glcontext;

    GLuint shaderProgram;
    GLuint VAO, VBO, EBO;
};

#endif /* graphics_hpp */
