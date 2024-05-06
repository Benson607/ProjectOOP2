#include "event.h"
#include"money.h"
#include"stat.h"

Event::Event()
{
	random_event = 0;
	stat.focus = 0;
	stat.vitality = 0;
	mon.money = 0;
}

void Event::Random_Event()
{
	srand(time(NULL));
	int event_num = rand() % 3;
	switch (event_num)
	{
	case 0:
		stat.vitality -= 10;
		std::cout << "A landmine exploded near you! Deduct 10 points of Vitality" << std::endl;
		break;
	case 1:
		stat.focus -= 1;
		std::cout << "??? Deduct 1 points of Focus" << std::endl;
		break;
	case 2:
		//stat += stat;
		mon.money += 100;//operator[]
		std::cout << "Met the LUCKY Cat! Increase all Status by 10 points and money increases by $100!!" << std::endl;
		break;
	default:
		break;
	}
}
