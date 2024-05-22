#include "shop.h"

Shop::Shop() {
	pos_x = 0;
	pos_y = 0;
	rect = Rect();
	buying = 1;
	//items = { Godsbeard(),GoldenRoot() , ,Item() };
	items.erase(items.begin() + rand() % 4);
	items.erase(items.begin() + rand() % 3);
	equit = std::vector<Equipment>(13);
	price = std::vector<int>(15);
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

void Shop::select_product()
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

//vector item (2) vector equit(13)
// random --> vector price
// for --> draw 
