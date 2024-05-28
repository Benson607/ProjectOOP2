#include "dice.h"

Dice::Dice() {
	//two situation --> focus 
	result = std::vector<char>(0);
	//Stat stat;
	//Money dollar;
	max_movement_points = 0;
	movement_points = 0;
	success_percent = 0;
}

void Dice::action(Stat& stat, int used_focus)
{
	srand(time(NULL));
	int isFail = 0;
	int isSuccess = 0;
	result.clear();
	movement_points = 0;

	max_movement_points = floor(stat.speed / 10);
	success_percent = floor(stat.speed / 100); //max = 90
	if (success_percent > 0.9) {
		success_percent = 0.9;
	}
	isSuccess += used_focus;
	for (int i = 0; i < isSuccess; i++) {
		result.push_back('T');
		movement_points++;
	}
	//the numbers of used focus cannot be bigger than max_movement point
	//another 1000 face dice --> if 90% <=90 -->Success 

	for (int i = 0; i < max_movement_points - isSuccess; i++) {
		int dice_result = rand() % 100;
		if (dice_result <= success_percent * 100) {
			result.push_back('T');
			movement_points++;
			isSuccess++;
		}
		else {
			result.push_back('F');
			isFail++;
		}
	}

	Money::money += 2 * isSuccess;
	if (isFail == max_movement_points) {
		stat.vitality_max *= 0.9;
	}
	if (isSuccess == max_movement_points) {
		//Perfect action
	}
}

void Dice::attack(Stat& stat, int used_focus, int num_of_dice, double success)
{
	int isFail = 0;
	int isSuccess = 0;
	srand(time(NULL));

	isSuccess += used_focus;
	for (int i = 0; i < isSuccess; i++) {
		result.push_back('T');
	}
	//the numbers of used focus cannot be bigger than max_movement point
	//another 1000 face dice --> if 90% <=90 -->Success 

	for (int i = 0; i < max_movement_points - isSuccess; i++) {
		int dice_result = rand() % 100;
		if (dice_result <= success_percent * 100) {
			result.push_back('T');
			movement_points += 1;
			success_percent = success;
		}
	}
	Money::money += 2 * isSuccess;
	if (isFail == num_of_dice) {
		stat.vitality_max *= 0.9;
	}
	if (isSuccess == num_of_dice) {
		//Perfect action
	}
}
