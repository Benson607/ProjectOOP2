#pragma once
#include<time.h>
#include <stdlib.h>

class Stat {
public:
	double vitality;
	double focus;
	double speed;
	double accuracy;
	double pAttack;
	double mAttack;
	double pDefense;
	double mDefense;

	Stat();
	double& operator[](int i);
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