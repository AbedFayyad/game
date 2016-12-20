#ifndef level_hpp
#define level_hpp

#include <map>
#include "sprite.hpp"
#include "vector.hpp"

class Level {
public:
    Level();
    ~Level();
private:
    std::map<Vector2<int>, Sprite> tileMap;
};

#endif
