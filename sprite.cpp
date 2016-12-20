#include "sprite.hpp"

Sprite::Sprite(std::string path, SDL_Rect src, SDL_Rect dst) {
    this->path = path;

    this->src = src;
    this->dst = dst;
}
