#pragma once
class Entity;
class IGraphicsComponent {
    public:
        virtual ~IGraphicsComponent(){}
        virtual void update(Position&) = 0;
};
