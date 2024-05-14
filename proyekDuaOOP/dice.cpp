#include "dice.h"

Dice::Dice() {
	//two situation --> focus 
	result = std::vector<int>(0);
	//Stat stat;
	//Money dollar;
	max_movement_points = 0;
	movement_points = 0;
	success_percent = 0;
}

void Dice::action(Stat& status)
{
	//focus
	max_movement_points = floor(stat.speed / 10);
	success_percent = floor(stat.speed / 100); //max = 90
	if (success_percent > 0.9) {
		success_percent = 0.9;
	}

	int isFail = 0;
	int isSuccess = 0;
	int tmp_max = max_movement_points;

	while (tmp_max--) {

		movement_points++;
	}

	if (isFail == max_movement_points) {
		stat.vitality_max *= 0.9;
	}
	else if (isSuccess == max_movement_points) {

	}

	dollar.money_increase(2 * isSuccess);
	for (int i = 0; i < movement_points; i++) {
		
	}
}
