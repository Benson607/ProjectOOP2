#pragma once

#include <string>
#include <vector>

#include "stat.h"

class Item {
public:
	Item();
	Stat status;
	std::vector<std::string> item_names;
};

class GoldenRoot :public Item {
	GoldenRoot();
	void use_items(Stat& target);
};

class Godsbeard :public Item {
	Godsbeard();
	void use_items(Stat& target);
};


class TeleportScroll :public Item {
	TeleportScroll();
	void use_items();
};

class Tent :public Item {
	Tent();
	void use_items(Stat& target);
};
