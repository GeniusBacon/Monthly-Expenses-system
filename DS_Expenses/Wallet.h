#pragma once

#include <string>
#include<map>
using namespace std;

struct category
{
	string cat_name;
	double spent;
};

struct Day
{
	double daySpent, spentCat[9] = {};
};

class Wallet
{
public:    // should be private and use getters
	double Balance;
	string  walletName;
	double totalspent;
	category categories[9];		
	Day viewDay[12][31];

public:
	Wallet(string, double);
	void displayWalletMenu();
	void addExpense();
	void editWallet();
	void viewWallet();
	void FilterByDate();
	void FilterByCat();
	void FilterByAmount();
};