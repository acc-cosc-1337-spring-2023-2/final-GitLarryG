//
#include "come_out_phase.h"
#include "point_phase.h"
#include "phase.h"


#include "come_out_phase.h"

RollOutcome ComeOutPhase::get_outcome(Roll* roll) {
    int roll_value = roll->roll_value();
    if (roll_value == 7 || roll_value == 11)
    {
        return RollOutcome::natural;
    }
    else if (roll_value == 2 || roll_value == 3 || roll_value == 12)
    {
        return RollOutcome::craps;
    }
    else
    {
        return RollOutcome::point;
    }
}