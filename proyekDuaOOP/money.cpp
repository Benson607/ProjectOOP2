#include "money.h"

int Money::money = 600;

Money::Money() {
}

int Money::money_deduct(int amount) {
	money -= amount;
	return money;
}

int Money::money_increase(int amount) {
	money += amount;
	return money;
}