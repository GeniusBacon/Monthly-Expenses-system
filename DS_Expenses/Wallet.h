#pragma once

#include <string>
using namespace std;


class Wallet
{
	public:    // should be private and use getters
	double Income;
	string  wallet_Name;
	
public:
	Wallet(string, double);
};

