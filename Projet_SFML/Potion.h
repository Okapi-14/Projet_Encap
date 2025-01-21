#pragma once
#include "Interactable.h"

class Potion : public Interactable {
private:
    float speedBoost; // Augmentation de vitesse
    bool isConsumed;  // Indique si la potion a déjà été utilisée

public:
    Potion(float boost);
    void interact(Player& player) override;
};
