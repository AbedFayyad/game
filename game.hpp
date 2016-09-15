#ifndef game_hpp
#define game_hpp

#include "graphics.hpp"
#include "scene.hpp"

#include <iostream>

class Game {
public:
    Game();
    ~Game();

private:
    std::map<std::string, Scene> scenes;
    Scene *activeScene;

    void gameLoop();

    // TODO Decide between pass by value/reference
    void addScene(const std::string name, Scene scene);
    void setActiveScene(const std::string name);

    void update(unsigned int elapsedTime);
    void draw(Graphics &graphics);
};

#endif
