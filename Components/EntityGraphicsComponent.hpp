#pragma once
#include "../Entity.hpp"
#include "IGraphicsComponent.hpp"

class EntityGraphicsComponent: public IGraphicsComponent {
    public:
        void update(Position&);
};
