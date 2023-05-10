//

#include "point_phase.h"
#include "come_out_phase.h"
#include "phase.h"

PointPhase::PointPhase(int p) : point(p) {}

RollOutcome PointPhase::get_outcome(Roll* roll, int point_value) {
    int roll_value = roll->roll_value();
    if (roll_value == point_value) {
        return RollOutcome::point;
    } else if (roll_value == 7) {
        return RollOutcome::seven_out;
    } else {
        return RollOutcome::nopoint;
    }
}