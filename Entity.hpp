#include "Components/IControlComponent.hpp"
#include "Components/IGraphicsComponent.hpp"

class Entity {
    public:
        Entity(IControlComponent *ctrlCmp, IGraphicsComponent *graphCmp);
        void update();
    private:
        IControlComponent *_control;
        IGraphicsComponent *_graphics;
};
