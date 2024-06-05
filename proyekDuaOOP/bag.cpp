#include "bag.h"

std::vector<Equipment> Bag::buy_in_E = std::vector<Equipment>(0);
std::vector<Item> Bag::buy_in_T = std::vector<Item>(0);
int Bag::pos_x = 0;
int Bag::pos_y = 0;
std::vector<std::string> Bag::statment = std::vector<std::string>(0);
std::vector<std::string> Bag::original_ui = std::vector<std::string>(0);
std::vector<std::string> Bag::bagUI = std::vector<std::string>(0);
std::vector<std::string> Bag::clear = std::vector<std::string>(0);
std::vector<std::vector<int>> Bag::pos_xy = std::vector<std::vector<int>>(0);
std::vector<int> Bag::store = std::vector<int>(3);

Bag::Bag() {
	pos_x = 0;
	pos_y = 0;
	statment = { "" };

	buy_in_T = std::vector<Item>(3, Item());
	buy_in_T[0].Godsbeard();
	buy_in_T[1].TeleportScroll();
	buy_in_T[2].Tent();

	for (int i = 0; i < 3; i++) {
		buy_in_T[i].amount = 0;
	}

	buy_in_E = std::vector<Equipment>(13, Equipment());
	buy_in_E[0].Weapon("WoodenSword");
	buy_in_E[1].Weapon("Hammer");
	buy_in_E[2].Weapon("GiantHammer");
	buy_in_E[3].Weapon("MagicWand");
	buy_in_E[4].Weapon("RitualSword");
	buy_in_E[5].Armour("WoodenShield");
	buy_in_E[6].Armour("PlateArmor");
	buy_in_E[7].Armour("LeatherArmor");
	buy_in_E[8].Armour("Robe");
	buy_in_E[9].Armour("LaurelWreath");
	buy_in_E[10].Accessory("HolyGrail");
	buy_in_E[11].Accessory("Shoes");
	buy_in_E[12].Accessory("Bracelet");

	for (int i = 0; i < 13; i++) {
		buy_in_E[i].amount = 0;
	}

	bagUI = { "" };
	//26
	clear = { "                             ", "                             ", "                             ", "                             ", "                             ","                             ",  "                             ", "                             ", "                             ", "                             ", "                             ", "                             ", "                             ", "                             ", "                             ", "                             ", "                             ", "                             ", "                             ", "                             ", "                             ", "                             ", "                             ", "                             ", "                             ", "                             " };
}


void Bag::bag_ui()
{
	original_ui = Draw::readSpace(53, 2, 26, 29);
	Draw::setColor();
	Draw::draw(clear, 53, 2);
	statment = { "___________Helper____________","Press W,S to select items    ","Press R to select the one you","want to use                  ","Press Y or N to confirm      " };
	Draw::draw(statment, 53, 23);

	pos_x = 2;
	pos_y = 53;

	int flag = 0;
	for (int i = 0; i < 16; i++) {
		if (i < 13) {
			if (buy_in_E[i].amount > 0) {
				store[0] = pos_x;
				store[1] = pos_y;
				store[2] = i;
				pos_xy.push_back(store);
				bagUI[0] = buy_in_E[i].name + " x " + std::to_string((int)(buy_in_E[i].amount));
				Draw::draw(bagUI, pos_y, pos_x);
				pos_x++;
				flag = 1;
			}
		}
		else {
			if (i == 13) {
				if (buy_in_T[0].amount > 0) {
					store[0] = pos_x;
					store[1] = pos_y;
					store[2] = 13;
					pos_xy.push_back(store);
					bagUI[0] = buy_in_T[0].name + " x " + std::to_string((int)(buy_in_T[0].amount));
					Draw::draw(bagUI, pos_y, pos_x);
					pos_x++;
					flag = 1;
				}
			}
			if (i == 14) {
				if (buy_in_T[1].amount > 0) {
					store[0] = pos_x;
					store[1] = pos_y;
					store[2] = 14;
					pos_xy.push_back(store);
					bagUI[0] = buy_in_T[1].name + " x " + std::to_string((int)(buy_in_T[1].amount));
					Draw::draw(bagUI, pos_y, pos_x);
					pos_x++;
					flag = 1;
				}
			}
			if (i == 15) {
				if (buy_in_T[2].amount > 0) {
					store[0] = pos_x;
					store[1] = pos_y;
					store[2] = 15;
					pos_xy.push_back(store);
					bagUI[0] = buy_in_T[2].name + " x " + std::to_string((int)(buy_in_T[2].amount));
					Draw::draw(bagUI, pos_y, pos_x);
					pos_x++;
					flag = 1;
				}
			}
		}
	}

	pos_x = 2;
	pos_y = 53;

	if (flag == 1) {
		bagUI = Draw::readSpace(53, 2, 1, 29);
		Draw::setColor(246);
		Draw::draw(bagUI, 53, 2);
	}
	else {
		if (Bag::pos_xy.size() == 0) {
			Draw::setColor();
			Bag::statment = { "Empty                        " };
			Draw::draw(Bag::statment, 53, 22);
		}
	}

}
