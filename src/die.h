//
#include <iostream>
#include <random>
#include <ctime>

#ifndef DIE_H
#define DIE_H

class Die {
public:
    Die();
    int roll();
    int rolled_value();
private:
    int sides;
    std::mt19937 rng;
    int roll_value;
};

#endif //DIE_H