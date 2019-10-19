#include "PlayerControlComponent.hpp"
#include "iostream"

void PlayerControlComponent::update(Position& position) {
    //updateSpeed();
    vx = 1, vy = 2;
    position.x += vx, position.y += vy;
}
