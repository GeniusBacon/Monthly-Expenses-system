#pragma once

#include <string>
#include <vector>
#include<map>

using namespace std;


struct Date
{
	int Day;
	int Month;
};


struct Expense
{
	Date date;
	int cat_id;
	double amount;
	string walletName;
};

class Wallet
{

public: // should be private and use getters
	string categories[9] = {"Food","Education","Transportation","Clothes","Health","Family","Debts","Education","others"};
	double Balance, totalspent, Debt;
	string  walletName, walletType;
	vector<Expense>  Expenses;	
	
	

public:
	Wallet(void);
	Wallet(string, string, double, double);
	void displayWalletMenu();
	void addExpense();
	void editWallet();
	void viewWallet();
	void NoFilter();
	void FilterByDate();
	void FilterByCat();
	void FilterByAmount();
	void FilterByDateAndCategory();
	void FilterByDateAndAmount();
	void FilterByCategoryAndAmount();
	void FilterByDateAndAmountandCategory();
};