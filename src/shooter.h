//
#include "die.h"
#include "roll.h"
#include<iostream>
#include<random>
#include<ctime>

#ifndef SHOOTER_H
#define SHOOTER_H

class Shooter {
    public:
        Roll* shoot(Die& die1, Die& die2);
        friend std::ostream& operator<<(std::ostream& out, const Shooter& s);
        ~Shooter();
    private:
        std::vector<Roll*> rolls;
};

#endif