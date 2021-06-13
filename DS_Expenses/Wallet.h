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

private:    // should be private and use getters
	string categories[9] = {"Food","Education","Transportation","Clothes","Health","Family","Debts","Education","others"};
	double Balance;
	string  walletName;
	double totalspent;
	vector<Expense>  Expenses;	// getter .. ?
	
	

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