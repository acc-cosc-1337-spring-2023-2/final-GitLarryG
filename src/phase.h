//create an abstract Phase class that will be the base class for derived classes ComeOutPhase and PointPhase.

//In phase.h file create an enum class RollOutcome with values natural, craps, point, seven_out, and nopoint

#include <iostream>
#include <random>
#include <ctime>
#include "die.h"
#include "roll.h"
#include "shooter.h"


#ifndef PHASE_H
#define PHASE_H

class RollOutcome {
    public:
        enum class Value {natural, craps, point, seven_out, nopoint};
        RollOutcome(Value v) : value(v) {}
        Value get_value() const {return value;}
    private:
        Value value;
};

class ComeOutPhase {
    public:
        RollOutcome get_outcome(Roll* roll);
};

class PointPhase {
    public:
        PointPhase(int p) : point(p) {}
        RollOutcome get_outcome(Roll* roll, int point_value);
    private:
        int point;
};

#endif