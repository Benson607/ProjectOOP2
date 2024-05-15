#pragma once

#include<string>

class Money {
public:
	Money();
	static int money;
	int money_deduct(int amount);
	int money_increase(int amount);
};