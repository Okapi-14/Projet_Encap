#ifndef KEY_H
#define KEY_H

#include "Interactable.h"

class Key : public Interactable {
private:
    bool collected;

public:
    Key();

    void interact(Player& player) override;
    void update(float deltaTime) override;
};

#endif
