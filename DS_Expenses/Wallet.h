#pragma once

#include <string>
using namespace std;

struct Date
{
	int Day;
	int Month;
	int Year;
};



class Wallet
{
public:    // should be private and use getters
	double Balance;
	string  wallet_Name;


public:
	Wallet(string, double);
	double Addexpense();
	void editWallet();
};