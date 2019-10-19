#include "Entity.hpp"
#include "Components/PlayerControlComponent.hpp"
#include "Components/EntityGraphicsComponent.hpp"

#include "iostream"

void test() {
    EntityGraphicsComponent* EGC = new EntityGraphicsComponent();
    PlayerControlComponent* PCC = new PlayerControlComponent();
    Entity* a = new Entity(PCC, EGC);
    a->update();
    std::cout << "test " << a->position.x << std::endl;
}
