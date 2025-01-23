#ifndef POTION_H
#define POTION_H

#include "Interactable.h"

class Potion : public Interactable {
private:
    float boost;
    bool consumed;

public:
    Potion(float boost);

    void interact(Player& player) override;
    void update(float deltaTime) override;
};

#endif
