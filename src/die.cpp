//
#include "die.h"

Die::Die() {
    sides = 6;
    rng.seed(static_cast<unsigned int>(time(0)));
    roll_value = roll();
}

int Die::roll() {
    std::uniform_int_distribution<int> dist(1, sides);
    roll_value = dist(rng);
    return roll_value;
}

int Die::rolled_value() {
    return roll_value;
}