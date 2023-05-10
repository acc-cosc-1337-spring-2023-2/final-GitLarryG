//
#include <iostream>
#include <random>
#include <ctime>
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"

#ifndef COMEOUTPHASE
#define COMEOUTPHASE

class ComeOutPhase : public Phase {
    public:
        RollOutcome get_outcome(Roll* roll, int point_value) override;
};


#endif