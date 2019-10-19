#ifndef ENTITY_CLASS
#define ENTITY_CLASS

class IControlComponent;
class IGraphicsComponent;

typedef struct {
    float x;
    float y;
} Position;

typedef struct {
    float x;
    float y;
} Scale;

class Entity {
    public:
        Entity(IControlComponent *ctrlCmp, IGraphicsComponent *graphCmp);
        void update();
    private:
        IControlComponent *_control;
        IGraphicsComponent *_graphics;
        Position position;
        Scale scale;
        float x = 0, y = 0;
        float scalex = 1, scaley = 1;
        
        friend void test();
        friend class IControlComponent;
        friend class IGraphicsComponent;
};
#include "Components/IControlComponent.hpp"
#include "Components/IGraphicsComponent.hpp"

#endif
