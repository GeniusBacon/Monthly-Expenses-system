#pragma once

#include <string>
#include <vector>
#include<map>

using namespace std;

struct category
{
	string cat_name;
	double spent;
};

struct Date
{
	int Day;
	int Month;
};

struct Day
{
	double daySpent, spentCat[9] = {};
};

struct Expense
{
	Date date;
	string cat_name;
};

class Wallet
{

private:    // should be private and use getters
	double Balance;
	string  walletName;
	double totalspent;
	category categories[9] = {};
	Day viewDay[12][31] = {};
	map<double, vector<Expense>> amountMap;

public:
	Wallet(string, double);

	string getName();
	/*double getBalance();
	double getTotalspent();
	string getCatName(int c);
	double getCatspent(int c);
	double getDayspent(int m, int d);
	double getDayCatspent(int m, int d, int c);
	
	void setBalance(double par);
	void setName(string par);
	void setTotalspent(double par);
	void setCatspent(int c, double par);
	void setDayspent(int m, int d, double par);
	void setDayCatspent(int m, int d, int c, double par);*/

	void displayWalletMenu();
	void addExpense();
	void editWallet();
	void viewWallet();
	void FilterByDate();
	void FilterByCat();
	void FilterByAmount();
	void FilterByDateAndCategory();
	void FilterByDateAndAmount();
	void FilterByCategoryAndAmount();
};