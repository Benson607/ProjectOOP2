#pragma once

#include <stdlib.h>

class Stat {
public:
	double vitality_max;
	double focus_max;
	double speed_max;
	double accuracy_max;
	double pAttack_max;
	double mAttack_max;
	double pDefense_max;
	double mDefense_max;

	double vitality;
	double focus;
	double speed;
	double accuracy;
	double pAttack;
	double mAttack;
	double pDefense;
	double mDefense;

	Stat();
	void operator=(Stat value);
	double& operator[](int i);
	void operator+=(Stat value);
};
/*
�ͩR��(Vitality)
�M�`�O(Focus)
�t��(Speed)
�R���v(Accuracy)
���z�����O(PAttack)
�]�k�����O(MAttack)
���z���m�O(PDefense)
�]�k���m�O(MDefense)
*/