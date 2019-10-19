#include "../Entity.hpp"
#include "IControlComponent.hpp"

class PlayerControlComponent: public IControlComponent {
    public:
        void update(Position&);
    private:
        float vx = 0, vy = 0;
        void updateSpeed();
};
