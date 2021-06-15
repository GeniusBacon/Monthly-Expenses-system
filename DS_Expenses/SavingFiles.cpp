#include "SavingFiles.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void SavingFiles::add_Wallet_to_file(vector<Wallet> wallets_vector)
{
	int flag = 0;
	ofstream file_object;
	vector<Expense>ExpensesCollector;
	file_object.open("Objects_saver.txt", ios::out);

	for (int i = 0; i < wallets_vector.size(); i++)
	{
		Wallet e= wallets_vector.at(i);
	file_object << e.walletName << endl << e.Balance << endl << e.totalspent << endl;
	int loopsize = e.Expenses.size();

	     for (int j = 0; j <loopsize; j++)
 	       {
			 ExpensesCollector.push_back(e.Expenses.at(j));
		   }
	if (flag < wallets_vector.size()- 1)
		file_object << endl;

	flag++;
	}
	add_Expense_to_file(ExpensesCollector);          //Wallet is deleted, But expenses isn't.+out of range mem location exception(solved).
	file_object.close();
	
}

void SavingFiles::add_Expense_to_file(vector<Expense> to_files_Expense)
{


	int flag = 0;
	ofstream file_object;
	file_object.open("Expenses_Saver.txt", ios::out);
	for (int i = 0; i < to_files_Expense.size(); i++)
	{
		Expense e = to_files_Expense.at(i);
		file_object << e.amount << endl << e.cat_id << endl << e.date.Day << endl <<e.date.Month << endl << e.walletName << endl;
		if (flag < to_files_Expense.size() - 1)
			file_object << endl;

		flag++;
	}
	file_object.close();
	
}
 void SavingFiles::read_Wallets_from_Files(vector<Wallet>&Read_Wallets)
{
	ifstream file_obj;

	Wallet File_Wallet;
	file_obj.open("Objects_saver.txt");
	

	if (!file_obj.is_open())
	{
		cout << "unable to open file";
		return;

	}
	while (file_obj >> File_Wallet.walletName >> File_Wallet.Balance >> File_Wallet.totalspent)
	{

		read_Expense_from_File(File_Wallet.Expenses,File_Wallet.walletName);
		Read_Wallets.push_back(File_Wallet);
		File_Wallet.Expenses.clear();
		
		
	}
	

}
 void SavingFiles::read_Expense_from_File(vector<Expense>&Read_Expenses,string WalletName)
{


	ifstream file_obj;
	Expense File_Expense;
	file_obj.open("Expenses_Saver.txt");

	if (!file_obj.is_open())
	{
		cout << "unable to open file";
		return;

	}
	while (file_obj >> File_Expense.amount >> File_Expense.cat_id >> File_Expense.date.Day >> File_Expense.date.Month >> File_Expense.walletName)
	{
		int res = File_Expense.walletName.compare(WalletName);

		if (res==0)
		{
			Read_Expenses.push_back(File_Expense);
		
		}		

	}

}