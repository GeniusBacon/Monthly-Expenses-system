#pragma once

#include <string>
using namespace std;


struct category
{
	string cat_name;
	double spent;

};



class Wallet
{
public:    // should be private and use getters
	double Balance;
	string  walletName;
	double totalspent;
	category categories[9];

public:
	Wallet(string, double);
	void Addexpense();
	void editWallet();
	void viewWallet();
};