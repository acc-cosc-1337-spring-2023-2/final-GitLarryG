//
#include "roll.h"
#include "die.h"

Roll::Roll(Die& die1, Die& die2) : die1(die1), die2(die2) {
    rolled = false;
    value = 0;
}

void Roll::roll_dice() {
    if (!rolled) {
        value = die1.roll() + die2.roll();
        rolled = true;
    }
}

int Roll::roll_value() const {
    if (rolled) {
        return value;
    } else {
        return -1; 
    }
}