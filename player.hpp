#ifndef player_hpp
#define player_hpp

#include "animated_sprite.hpp"
#include "graphics.hpp"
#include "vector.hpp"

class Player {
public:
    Player();
//    Player(Graphics &graphics, Vector2<float> position);
    ~Player();

    void update(unsigned int elapsedTime);
    void draw();

    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

    void stopMoving();
private:
    AnimatedSprite sprite;
    Vector2<float> position;
};

#endif
