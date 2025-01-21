#pragma once
#include "Interactable.h"

class Key : public Interactable {
private:
    bool isCollected;

public:
    Key();
    void interact(Player& player) override;
};
