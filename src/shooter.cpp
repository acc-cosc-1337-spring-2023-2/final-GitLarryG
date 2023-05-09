//
#include "shooter.h"

Roll* Shooter::shoot(Die& die1, Die& die2)
{
    Roll* roll = new Roll(die1, die2);
    roll->roll_dice();
    rolls.push_back(roll);
    return roll;
}

std::ostream& operator<<(std::ostream& out, const Shooter& s)
{
    for (auto roll : s.rolls)
    {
        out << "Roll value: " << roll->roll_value() << "\n";
    }
    return out;
}

Shooter::~Shooter()
{
    for (auto roll : rolls)
    {
        delete roll;
        roll = nullptr;
    }
}