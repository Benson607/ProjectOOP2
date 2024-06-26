#include "shop.h"

Shop::Shop() {
	pos_x = 0;
	pos_y = 0;
	rand_no1 = 0;
	rand_no2 = 0;
	rand_no3 = 0;

	position = std::vector<int>(2);
	pos_x_y = std::vector<std::vector<int>>(0);
	record = { "" };

	items = std::vector<Item>(4, Item());
	items[0].Godsbeard();
	items[1].TeleportScroll();
	items[2].Tent();
	items[3].GoldenRoot();

	equip = std::vector<Equipment>(13, Equipment());
	equip[0].Weapon("WoodenSword");
	equip[1].Weapon("Hammer");
	equip[2].Weapon("GiantHammer");
	equip[3].Weapon("MagicWand");
	equip[4].Weapon("RitualSword");
	equip[5].Armour("WoodenShield");
	equip[6].Armour("PlateArmor");
	equip[7].Armour("LeatherArmor");
	equip[8].Armour("Robe");
	equip[9].Armour("LaurelWreath");
	equip[10].Accessory("HolyGrail");
	equip[11].Accessory("Shoes");
	equip[12].Accessory("Bracelet");

	output = std::vector<std::string>(3);
	statment = { "" };
	money_stat = { "" };
	//alt
	shop_ui = { //i = x j = y
		"Products---------------------------------------------------------------------------------------------------------------------------------------------------",
		"-                              -                              -                              -                               * How to Buy:                -",
		"-                              -                              -                              -                               * Press W,A,S,D to select the-",
		"-                              -                              -                              -                               * product                    -",
		"-                              -                              -                              -                               * Press R to choose the one  -",
		"-      Amount:                 -                              -                              -                               * you want to buy            -",
		"-                              -                              -                              -                               * Press Y or N to confirm    -",
		"-      Price:                  -                              -                              -                               * whether you want to buy the-",
		"-                              -                              -                              -                               * selected product           -",
		"-                              -                              -                              -                               * You can check the brought  -",
		"-----------------------------------------------------------------------------------------------------------------------------* products in you bag        -",
		"-                              -                              -                              -                               ******************************",
		"-                              -                              -                              -                               * Purchase Status:           -",
		"-                              -                              -                              -                               *                            -",
		"-                              -                              -                              -                               *                            -",
		"-                              -                              -                              -                               *                            -",
		"-                              -                              -                              -                               *                            -",
		"-                              -                              -                              -                               *                            -",
		"-                              -                              -                              -                               *                            -",
		"-                              -                              -                              -                               *                            -",
		"-----------------------------------------------------------------------------------------------------------------------------*                            -",
		"-                              -                              -                              -                               *                            -",
		"-                              -                              -                              -                               *                            -",
		"-                              -                              -                              -                               *                            -",
		"-                              -                              -                              -                               *                            -",
		"-                              -                              -                              -                               *                            -",
		"-                              -                              -                              -                               *                            -",
		"-                              -                              -                              -                               *                            -",
		"-                              -                              -                              -                               *                            -",
		"-                              -                              -                              -                               *                            -",
		"-----------------------------------------------------------------------------------------------------------------------------*                            -",
		"-                              -                              -                              -                               *                            -",
		"-                              -                              -                              -                               *                            -",
		"-                              -                              -                              -                               *                            -",
		"-                              -                              -                              -                               *                            -",
		"-                              -                              -                              -                               *                            -",
		"-                              -                              -                              -                               *                            -",
		"-                              -                              -                              -                               *                            -",
		"-                              -                              -                              -                               *                            -",
		"-                              -                              -                              -                               *                            -",
		"-----------------------------------------------------------------------------------------------------------------------------------------------------------",
	};

	grid_ui = {
		"                              ",
		"                              ",
		"                              ",
		"                              ",
		"                              ",
		"                              ",
		"                              ",
		"                              ",
		"                              "
	};
}

void Shop::select_product()
{
	int tmp_x = pos_x + 2;
	int tmp_y = pos_y + 5;

	int input = _getch();
	while (input != 27) {
		switch (input)
		{
		case 119://w
			if (pos_x > 1) {
				record = Draw::readSpace(pos_y, pos_x, 9, 30);
				Draw::setColor();
				Draw::draw(record, pos_y, pos_x);
				pos_x -= 10;
				Draw::setColor(246);
				record = Draw::readSpace(pos_y, pos_x, 9, 30);
				Draw::draw(record, pos_y, pos_x);
			}
			break;
		case 97://a
			if (pos_y > 1) {
				record = Draw::readSpace(pos_y, pos_x, 9, 30);
				Draw::setColor();
				Draw::draw(record, pos_y, pos_x);
				pos_y -= 31;
				Draw::setColor(246);
				record = Draw::readSpace(pos_y, pos_x, 9, 30);
				Draw::draw(record, pos_y, pos_x);
			}
			break;
		case 115://s
			if (pos_x < 31) {
				record = Draw::readSpace(pos_y, pos_x, 9, 30);
				Draw::setColor();
				Draw::draw(record, pos_y, pos_x);
				pos_x += 10;
				Draw::setColor(246);
				record = Draw::readSpace(pos_y, pos_x, 9, 30);
				Draw::draw(record, pos_y, pos_x);
			}
			break;
		case 100://d
			if (pos_y >= 1 && pos_y < 94) {
				record = Draw::readSpace(pos_y, pos_x, 9, 30);
				Draw::setColor();
				Draw::draw(record, pos_y, pos_x);
				pos_y += 31;
				Draw::setColor(246);
				record = Draw::readSpace(pos_y, pos_x, 9, 30);
				Draw::draw(record, pos_y, pos_x);
			}
			break;
		case 114://r
			record = Draw::readSpace(pos_y, pos_x, 9, 30);
			Draw::setColor(27);
			Draw::draw(record, pos_y, pos_x);

			Draw::setColor();
			statment = { "Sure to buy?               " };
			Draw::draw(statment, 127, 13);
			//y 127 x 13
			//select

			while (input != 121 && input != 110) {
				input = _getch();
				if (input == 121) {//y
					statment = { "Brought                    " };
					tmp_x = pos_x + 2;
					tmp_y = pos_y + 5;

					for (int i = 0; i < pos_x_y.size(); i++) {
						if (pos_x_y[i][0] == tmp_x && pos_x_y[i][1] == tmp_y && i < 13) {
							if (equip[i].amount > 0) {
								if (equip[i].price > Money::money) {
									statment = { "No enough money!              " };
								}
								else {
									equip[i].amount -= 1;
									Money::money -= equip[i].price;
									Bag::buy_in_E[i].amount++;
								}
							}
							else {
								statment = { "Sold Out!                  " };
							}
							output = { equip[i].name," ", "Amount: "," ", "Price: " };
							output[2] = output[2] + std::to_string((int)(equip[i].amount));
							output[4] = output[4] + std::to_string((int)(equip[i].price));
							break;
						}
						else if (pos_x_y[i][0] == tmp_x && pos_x_y[i][1] == tmp_y && i >= 13) {
							if (i == 13) {
								if (items[rand_no1].amount > 0) {
									if (items[rand_no1].price > Money::money) {
										statment = { "No enough money!              " };
									}
									else {
										items[rand_no1].amount -= 1;
										Money::money -= items[rand_no1].price;
										Bag::buy_in_T[rand_no1].amount++;
									}
								}
								else {
									statment = { "Sold Out!                  " };
								}
								output = { items[rand_no1].name," ", "Amount: "," ", "Price: " };
								output[2] = output[2] + std::to_string((int)(items[rand_no1].amount));
								output[4] = output[4] + std::to_string((int)(items[rand_no1].price));
							}if (i == 14) {
								if (items[rand_no2].amount > 0) {
									if (items[rand_no2].price > Money::money) {
										statment = { "No enough money!              " };
									}
									else {
										items[rand_no2].amount -= 1;
										Money::money -= items[rand_no2].price;
										Bag::buy_in_T[rand_no2].amount++;
									}
								}
								else {
									statment = { "Sold Out!                  " };
								}
								output = { items[rand_no2].name," ", "Amount: "," ", "Price: " };
								output[2] = output[2] + std::to_string((int)(items[rand_no2].amount));
								output[4] = output[4] + std::to_string((int)(items[rand_no2].price));
							}if (i == 15) {
								if (items[rand_no3].amount > 0) {
									if (items[rand_no3].price > Money::money) {
										statment = { "No enough money!              " };
									}
									else {
										items[rand_no3].amount -= 1;
										Money::money -= items[rand_no3].price;
										Bag::buy_in_T[rand_no3].amount++;
									}
								}
								else {
									statment = { "Sold Out!                  " };
								}
								output = { items[rand_no3].name, " ", "Amount: ", " ", "Price: " };
								output[2] = output[2] + std::to_string((int)(items[rand_no3].amount));
								output[4] = output[4] + std::to_string((int)(items[rand_no3].price));
							}
							break;
						}
					}
					Draw::setColor(246);
					Draw::draw(grid_ui, pos_y, pos_x);
					Draw::draw(output, tmp_y, tmp_x);
					record = Draw::readSpace(pos_y, pos_x, 9, 30);
					Draw::draw(record, pos_y, pos_x);

					Draw::setColor();
					money_stat[0] = ("                           ");
					Draw::draw(money_stat, 127, 39);
					money_stat[0] = ("Money: " + std::to_string(Money::money));
					Draw::draw(money_stat, 127, 39);
					Draw::draw(statment, 127, 13);
					//bag
					break;
				}
				if (input == 110) {//n
					record = Draw::readSpace(pos_y, pos_x, 9, 30);
					Draw::setColor(246);
					Draw::draw(record, pos_y, pos_x);
					Draw::setColor();
					statment = { "                           " };
					Draw::draw(statment, 127, 13);
					break;
				}
			}
			break;
		case 27://esc
			break;
		}
		input = _getch();
		Draw::setColor();
		statment = { "                           " };
		Draw::draw(statment, 127, 13);
	}

	Draw::setColor();
	statment = { "Are you sure to exit shop?  " };
	Draw::draw(statment, 127, 13);
	input = _getch();
	if (input == 110) {
		//unchange
		statment = { "                           " };
		Draw::draw(statment, 127, 13);
		select_product();
	}
	else {
		system("CLS");
		return;
	}
}

void Shop::show()
{
	srand(time(NULL));

	do {
		rand_no1 = rand() % 4;
		rand_no2 = rand() % 4;
		rand_no3 = rand() % 4;
	} while (rand_no1 == rand_no2 || rand_no2 == rand_no3 || rand_no1 == rand_no3);

	Draw::draw(shop_ui, 0, 0);
	pos_x = 3;
	pos_y = 6;
	for (int i = 0; i < 4; i++) {
		//i*4+j
		for (int j = 0; j < 4; j++) {
			if (i * 4 + j <= 12) {
				position[0] = pos_x;
				position[1] = pos_y;
				pos_x_y.push_back(position);
				output = { equip[i * 4 + j].name," ", "Amount: "," ", "Price: " };
				output[2] = output[2] + std::to_string((int)(equip[i * 4 + j].amount));
				output[4] = output[4] + std::to_string((int)(equip[i * 4 + j].price));
				Draw::draw(output, pos_y, pos_x);
				pos_y += 31;
			}
			else {
				position[0] = pos_x;
				position[1] = pos_y;
				pos_x_y.push_back(position);

				output = { items[rand_no1].name," ", "Amount: "," ", "Price: " };
				output[2] = output[2] + std::to_string((int)(items[rand_no1].amount));
				output[4] = output[4] + std::to_string((int)(items[rand_no1].price));
				Draw::draw(output, pos_y, pos_x);
				pos_y += 31;
				position[0] = pos_x;
				position[1] = pos_y;
				pos_x_y.push_back(position);

				output = { items[rand_no2].name," ", "Amount: "," ", "Price: " };
				output[2] = output[2] + std::to_string((int)(items[rand_no2].amount));
				output[4] = output[4] + std::to_string((int)(items[rand_no2].price));
				Draw::draw(output, pos_y, pos_x);
				pos_y += 31;
				position[0] = pos_x;
				position[1] = pos_y;
				pos_x_y.push_back(position);

				output = { items[rand_no3].name," ", "Amount: "," ", "Price: " };
				output[2] = output[2] + std::to_string((int)(items[rand_no3].amount));
				output[4] = output[4] + std::to_string((int)(items[rand_no3].price));
				Draw::draw(output, pos_y, pos_x);
				break;
			}
		}
		pos_x += 10;
		pos_y = 6;
	}

	Draw::setColor(246);
	pos_x = 1;
	pos_y = 1;
	record = Draw::readSpace(pos_y, pos_x, 9, 30);
	Draw::draw(record, pos_y, pos_x);
	Draw::setColor();
	money_stat[0] = ("Money: " + std::to_string(Money::money));
	Draw::draw(money_stat, 127, 39);
}
