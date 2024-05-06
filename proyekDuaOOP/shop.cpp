#include "shop.h"
#include "money.h"

Shop::Shop() {
	pos_x = 0;
	pos_y = 0;
	icon = '$';
	buying = 1;
	//alt
	shop_ui = {
		"Products---------------------------------------------------------------------------------------------------------------------------------------------------",
		"-                              -                               -                               -                             * How to Buy:                -",
		"-                              -                               -                               -                             * Press W,A,S,D to select the-",
		"-                              -                               -                               -                             * product                    -",
		"-                              -                               -                               -                             * Press R to choose the one  -",
		"-                              -                               -                               -                             * you want to buy            -",
		"-                              -                               -                               -                             * Press Y or N to confirm    -",
		"-                              -                               -                               -                             * whether you want to buy the-",
		"-                              -                               -                               -                             * selected product           -",
		"-                              -                               -                               -                             * You can check the brought  -",
		"-----------------------------------------------------------------------------------------------------------------------------* products in you bag        -",
		"-                              -                               -                               -                             ******************************",
		"-                              -                               -                               -                             * Purchase Status:           -",
		"-                              -                               -                               -                             *                            -",
		"-                              -                               -                               -                             *                            -",
		"-                              -                               -                               -                             *                            -",
		"-                              -                               -                               -                             *                            -",
		"-                              -                               -                               -                             *                            -",
		"-                              -                               -                               -                             *                            -",
		"-                              -                               -                               -                             *                            -",
		"-----------------------------------------------------------------------------------------------------------------------------*                            -",
		"-                              -                               -                               -                             *                            -",
		"-                              -                               -                               -                             *                            -",
		"-                              -                               -                               -                             *                            -",
		"-                              -                               -                               -                             *                            -",
		"-                              -                               -                               -                             *                            -",
		"-                              -                               -                               -                             *                            -",
		"-                              -                               -                               -                             *                            -",
		"-                              -                               -                               -                             *                            -",
		"-                              -                               -                               -                             *                            -",
		"-----------------------------------------------------------------------------------------------------------------------------*                            -",
		"-                              -                               -                               -                             *                            -",
		"-                              -                               -                               -                             *                            -",
		"-                              -                               -                               -                             *                            -",
		"-                              -                               -                               -                             *                            -",
		"-                              -                               -                               -                             *                            -",
		"-                              -                               -                               -                             *                            -",
		"-                              -                               -                               -                             *                            -",
		"-                              -                               -                               -                             *                            -",
		"-                              -                               -                               -                             *                            -",
		"-----------------------------------------------------------------------------------------------------------------------------------------------------------",
	};
}

void Shop::select_item()
{
	int input = _getch();
	switch (input)
	{
	case 119:
		if (pos_y > 0) {
			pos_y -= 1;
		}
		break;
	case 97:
		if (pos_x > 0) {
			pos_x -= 1;
		}
		break;
	case 115:
		if (pos_y < get_y() - 1) {
			pos_y += 1;
		}
		break;
	case 100:
		if (pos_x < get_x() - 1) {
			pos_x += 1;
		}
		break;
		//case 114:
		//	bgm.playPressBGM();
		//	map[nowy][nowx].roll();
		//	break;
	case 27:
		buying = 0;
		break;
	default:
		break;
	}
}

int Shop::get_x()
{
	return 0;
}

int Shop::get_y()
{
	return 0;
}