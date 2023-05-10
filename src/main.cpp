#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "point_phase.h"
#include "come_out_phase.h"

#include <memory>




using namespace std; using std::cout; using std::cin;


int main() 
{
	srand(time(0));
	Die die1;
	Die die2;
	Shooter shooter;

	Roll* roll;

	roll = shooter.throw_die(die1, die2);

	ComeOutPhase come_out_phase;

	while (come_out_phase.get_outcome(roll) == RollOutcome::natural || come_out_phase.get_outcome(roll) == RollOutcome::craps)
	{
		cout<< "Rolled " << roll->roll_value() << "\n" << "Roll again!\n";

		roll = shooter.throw_die(die1, die2);
	}

	cout<< "Rolled " << roll->roll_value() << " start of point phase\n";
	cout<< "Roll until " << roll->roll_value() << " or a 7 is rolled\n";

	int point = roll->roll_value();
	roll = shooter.throw_die(die1, die2);

	PointPhase point_phase(point);

	while (point_phase.get_outcome(roll) != RollOutcome::point && point_phase.get_outcome(roll) != RollOutcome::seven_out)
	{
		cout << "You rolled a " << roll->roll_value() << "\n" << "Roll again!\n";

		roll = shooter.throw_die(die1, die2);
	}

	//Display rolled value with the text end of point phase
	cout << "You rolled a " << roll->roll_value() << "\n" << "End of point phase!\n";

	cout<< shooter;


	return 0;
}