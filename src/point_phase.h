//
#include <iostream>
#include <random>
#include <ctime>
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"

#ifndef POINTPHASE
#define POINTPHASE

class PointPhase : public Phase {
public:
    PointPhase(int p);
    RollOutcome get_outcome(Roll* roll, int point_value) override;
private:
    int point;
};

#endif