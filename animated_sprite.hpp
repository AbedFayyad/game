#ifndef animated_sprite_hpp
#define animated_sprite_hpp

#include "globals.hpp"
#include "graphics.hpp"
#include "sprite.hpp"

#include <SDL2/SDL.h>
#include <map>
#include <string>
#include <vector>

class AnimatedSprite : public Sprite {
public:
    AnimatedSprite();
    AnimatedSprite(Graphics &graphics, const std::string path,
            SDL_Rect sourceRect, unsigned int frameTime);

    // Add an animation by specifying a name and frame coordinates
    void addAnimation(std::string name,
            std::vector<Point<unsigned int> > frames);

    // Run an animation by name
    void runAnimation(std::string name);

    // Stop an ongoing animation
    void stopAnimation();

    // Update this sprite's current appearance if enough time has passed
    void update(unsigned int elapsedTime);
private:

    // The length of time in ms until the next frame in the animation is shown
    unsigned int frameTime;

    // The length of time in ms that has passed since the last frame was shown
    unsigned int timeSinceLastFrame;

    // The currently running animation
    std::vector<Point<unsigned int> > currentAnimation;

    // Index of the current frame in the current animation
    unsigned int currentFrame;

    // A map of animation names and their frames
    std::map<std::string, std::vector<Point<unsigned int> > > animations;

    // Whether or not an animation is being played
    bool animationIsRunning;

    // Sets the current animation's frame to the next one in line
    void advanceFrame();
};

#endif
