//create an abstract Phase class that will be the base class for derived classes ComeOutPhase and PointPhase.

//In phase.h file create an enum class RollOutcome with values natural, craps, point, seven_out, and nopoint

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
        virtual RollOutcome get_outcome(Roll* roll, int point_value) = 0;
};

#endif