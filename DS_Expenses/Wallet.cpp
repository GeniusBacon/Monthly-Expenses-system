#include "Wallet.h"

#include <iostream>
using namespace std;

/*struct category
{
    string cat_name;
    double spent;

};*/

struct Day
{
    double daySpent, spentCat[9] = {};


}viewDay[12][31];



Wallet::Wallet(string name, double income)
{
    walletName = name;
    Balance = income;
    totalspent = 0;
    category categories2[9] = { {"Food", 0}, { "Education", 0 }, { "Transportation", 0 },
        { "Clothes", 0 }, { "Health", 0 }, { "Family", 0 }, { "Debts", 0 }, { "Bills", 0 }, { "Others", 0 } };
    copy(categories2, categories2 + 9, categories);
}


void Wallet::Addexpense()
{
    int categChoice;
    double spent;
    cout << "How much did you spend? " << endl;
    cin >> spent;
    totalspent += spent;
    if (spent <= Balance)
    {
        Balance -= spent;
        cout << "Choose the category in which you spent your money: " << endl;
        for (int i = 0; i < 9; i++)
            cout << i + 1 << ". " << categories[i].cat_name << endl;
        cin >> categChoice;
        // date
        categories[--categChoice].spent += spent;

        cout << "Your current balance: " << Balance << endl;
        return ;
    }
    else if(spent>Balance)
        cout << "Not enough balance. " << endl;
    system("CLS");
   
    return ;
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
        walletName = name;
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

void Wallet::viewWallet()
{
    cout << "The total spent money is :" << totalspent<< "\nChoose how you want to filter your expenses:\n";
    cout << "1-Filter by date.\n2-Filter by category.\n3-Filter by amount of money.\n";
    // more than one filter.
    int choice, categChoice;
    cin >> choice;
    if (choice == 1)
    {
        // filter by date
    }
    else if (choice == 2)
    {
        cout << "Choose the category by which you want to filter your expenses: " << endl;
        for (int i = 0; i < 9; i++)
            cout << i + 1 << ". " << categories[i].cat_name << endl;
        cin >> categChoice;
        cout << "You have spent " << categories[--categChoice].spent << " on " << categories[categChoice].cat_name << endl;
    }
    else if (choice == 3)
    {
        // filter by amount
    }
}