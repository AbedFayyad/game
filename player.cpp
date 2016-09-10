#include "player.hpp"

#include "animated_sprite.hpp"
#include "globals.hpp"
#include "graphics.hpp"

#include <SDL2/SDL.h>

Player::Player() {}

Player::Player(Graphics &graphics, Point<float> position)
    : sprite(AnimatedSprite(graphics, "content/sprites/img.png",
                (SDL_Rect) {0, 0, 16, 16}, 160))
    , position(position) {
    std::vector<Point<unsigned int> > frames;
    frames.push_back((Point<unsigned int>) {0, 0});
    frames.push_back((Point<unsigned int>) {1, 0});
    frames.push_back((Point<unsigned int>) {2, 0});
    frames.push_back((Point<unsigned int>) {3, 0});
    frames.push_back((Point<unsigned int>) {4, 0});
    frames.push_back((Point<unsigned int>) {5, 0});
    sprite.addAnimation("run", frames);
}

Player::~Player() {}

void Player::update(unsigned int elapsedTime) {
    sprite.update(elapsedTime);
}

void Player::draw() {
    sprite.draw(position.x, position.y);
}

void Player::moveRight() {
    position.x += 0.02;
    sprite.runAnimation("run");
}

void Player::moveLeft() {
    position.x -= 0.02;
}

void Player::moveUp() {
    position.y -= 0.02;
}

void Player::moveDown() {
    position.y += 0.02;
}

void Player::stopMoving() {
    sprite.stopAnimation();
}
