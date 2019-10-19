#pragma once
class IControlComponent {
    public:
        virtual ~IControlComponent() {};
        virtual void update(Position&) = 0;
};
