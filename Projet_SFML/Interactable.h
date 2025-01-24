#ifndef INTERACTABLE_H
#define INTERACTABLE_H

#include "Player.h"
#include "Entity.h"

class Interactable : public Entity {
public:
    virtual void interact(Player& player) = 0;
}
#endif
