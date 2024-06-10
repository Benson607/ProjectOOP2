#include "event.h"

Event::Event() {
	random_event = 0;
	stat.focus = 0;
	stat.vitality = 0;
	stat.hitrate = 0;
	stat.mAttack = 0;
	stat.mDefense = 0;
	stat.pAttack = 0;
	stat.pDefense = 0;
	stat.speed = 0;
}

void Event::Random_Event(Stat& status) {
	srand(time(NULL));
	random_event = rand() % 3;
	switch (random_event) {
	case 0:
		stat.vitality = -10;
		std::cout << "A landmine exploded near you! Deduct 10 points of Vitality" << std::endl;
		break;
	case 1:
		stat.focus = -1;
		std::cout << "Last night You slept at 3:00, now you are mentally weak. Deduct 1 points of Focus" << std::endl;
		break;
	case 2:
		for (int i = 0; i < 8; i++) {
			stat[i] += 10;
		}
		Money().money_increase(100);
		std::cout << "Met the LUCKY Cat! Increase all Status by 10 points and money increases by $100!!" << std::endl;
		break;
	default:
		break;
	}
	status += stat;
}
