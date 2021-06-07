#include "Wallet.h"

#include <iostream>
using namespace std;

struct category
{
    string cat_name;
    double spent;

}categories[] = { {"Food", 0} , {"Education", 0} , {"Transportation", 0} ,
    {"Clothes", 0} , {"Health", 0} , {"Family", 0} , {"Debts", 0}, {"Bills", 0} , {"Others", 0} };



Wallet::Wallet(string name, double income)
{
    wallet_Name = name;
    Balance = income;
}

double Wallet::Addexpense()
{
    int categChoice;
    double spent;
    Date date;
    cout << "How much did you spend? " << endl;
    cin >> spent;
    if (spent <= Balance)
    {
        Balance -= spent;
        cout << "Choose the category in which you spent your money: " << endl;
        for (int i = 0; i < 9; i++)
        {
            cout << i + 1 << ". " << categories[i].cat_name << endl;

        }
        cin >> categChoice;
        // date
        categories[categChoice - 1].spent += spent;

        return Balance;
    }
    else
        cout << "Not enough balance. " << endl;
    system("CLS");
}

void Wallet::editWallet()
{
    int choice;
    cout << "Please choose what you would like to do: \n\n";
    cout << "1-Edit the wallet's name. \n";
    cout << "2-Edit the wallet's balance.\n";
    cin >> choice;
    if (choice == 1)
    {
        cout << "\n Enter the new name: ";
        string name;
        cin >> name;
        wallet_Name = name;
        cout << "Editing done successfully.\n";
    }
    else if (choice == 2)
    {
        cout << "\n Enter the new current balance: ";
        int balance;
        cin >> balance;
        Balance = balance;
    }
    else cout << "\nInvalid choice number\n\n";
    system("CLS");

}