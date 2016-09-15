#ifndef scene_hpp
#define scene_hpp

#include "graphics.hpp"

class Scene {
public:
    void update(unsigned int elapsedTime);
    void draw(Graphics &graphics);
private:
};

#endif
