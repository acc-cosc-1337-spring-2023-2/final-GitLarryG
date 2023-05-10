//
#include <iostream>
#include <random>
#include <ctime>
#include "die.h"
#include "roll.h"
#include "shooter.h"


#ifndef PHASE
#define PHASE

enum class RollOutcome {
    natural,
    craps,
    point,
    seven_out,
    nopoint
};

class Phase {
    public:
        virtual RollOutcome get_outcome(Roll* roll) = 0;
};

#endif