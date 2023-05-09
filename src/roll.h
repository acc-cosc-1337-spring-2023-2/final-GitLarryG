//roll two die
#include "die.h"
#include <iostream>
#include <random>
#include <ctime>

#ifndef ROLL_H
#define ROLL_H

class Roll {
public:
    Roll(Die& die1, Die& die2);
    void roll_dice();
    int roll_value() const;
private:
    Die& die1;
    Die& die2;
    bool rolled;
    int value;
};
#endif