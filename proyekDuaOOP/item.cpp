#include "item.h"

Item::Item() {
	status.vitality = 0;
	status.focus = 0;
}

void Item::use_items(int kind)
{
	switch (kind)
	{
	case 0://Godsbeard
		status.vitality += 25;
		break;
	case 1://GoldenRoot
		status.focus += 3;
		break;
	case 2://TeleportScroll

		break;
	case 3://Tent
		status.vitality += 50;
		status.focus += 5;
		break;
	default:
		break;
	}
}
