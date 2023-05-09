//
#include "phase.h"

RollOutcome ComeOutPhase::get_outcome(Roll* roll)
{
    int roll_value = roll->roll_value();
    if (roll_value == 7 || roll_value == 11)
    {
        return RollOutcome(RollOutcome::Value::natural);
    }
    else if (roll_value == 2 || roll_value == 3 || roll_value == 12)
    {
        return RollOutcome(RollOutcome::Value::craps);
    }
    else
    {
        return RollOutcome(RollOutcome::Value::point);
    }
}

RollOutcome PointPhase::get_outcome(Roll* roll, int point_value)
{
    int roll_value = roll->roll_value();
    if (roll_value == point_value)
    {
        return RollOutcome(RollOutcome::Value::point);
    }
    else if (roll_value == 7)
    {
        return RollOutcome(RollOutcome::Value::seven_out);
    }
    else
    {
        return RollOutcome(RollOutcome::Value::nopoint);
    }
}