#include "Wallet.h"

#include <iostream>
using namespace std;

/*struct category
{
    string cat_name;
    double spent;

};*/
struct Date
{
    int Day;
    int Month;
};
struct Day
{
    double daySpent, spentCat[9] = {};


}viewDay[12][31];



Wallet::Wallet(string name, double income)
{
    walletName = name;
    Balance = income;
    totalspent = 0;
    categories[0] = { "Food", 0 };
    categories[1] = { "Education", 0 };
    categories[2] = { "Transportation", 0 };
    categories[3] = { "Clothes", 0 };
    categories[4] = { "Health", 0 };
    categories[5] = { "Family", 0 };
    categories[6] = { "Debts", 0 };
    categories[7] = { "Education", 0 };
    categories[8] = { "others", 0 };
    
}

void Wallet::Addexpense()
{
    int categChoice;
    cout << "How much did you spend? " << endl;
    double spent;
    cin >> spent;
    totalspent += spent;
    if (spent <= Balance)
    {
        Date date;
        Balance -= spent;
        cout << "Choose the category in which you spent your money: " << endl;
        for (int i = 0; i < 9; i++)
            cout << i + 1 << ". " << categories[i].cat_name << endl;

        cin >> categChoice;
        if (categChoice < 1 || categChoice>9)
        {
            cout << "Wrong category number,returning to main menu...\n";
            return;
        }
       //Spent Amount /Day  + viewDay allocation 
        cout << "please enter the Month that you spent this expense in:";
        cin >> date.Month;
        if (date.Month > 12 || date.Month < 1)
        {
            cout << "Wrong Month Input\n";
            return;
        }
        cout << "please enter the Day that you spent this expense in:";
        cin >> date.Day;
        if ((date.Month==2 &&date.Day>28)||((date.Month==4|| date.Month==6|| date.Month==9|| date.Month==11)&&date.Day>30) || date.Day > 31 || date.Day < 1)
        {
            cout << "Wrong Day Input\n";
            return;
        }
        viewDay[date.Month-1][date.Day-1].daySpent+=spent;
        viewDay[date.Month - 1][date.Day - 1].spentCat[categChoice] += spent;
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
        Date date;
        cout << "please enter the month you want to view:";
        cin >> date.Month;
        if (date.Month > 12 || date.Month < 1)
        {
            cout << "Wrong Month Input\n";
            return;
        }
        cout << "please enter the Day you want to view:";
        cin >> date.Day;
        if ((date.Month == 2 && date.Day > 28) || ((date.Month == 4 || date.Month == 6 || date.Month == 9 || date.Month == 11) && date.Day > 30) || date.Day > 31 || date.Day < 1)
        {
            cout << "Wrong Day Input\n";
            return;
        }
        cout << "you have spent " << viewDay[date.Month - 1][date.Day - 1].daySpent << " in " << date.Day << "/" << date.Month;
        cout << "\n\nHere is a detailed description of your expenses in that day: \n\n";
        for (int i = 0; i < 9; i++)
            if (viewDay[date.Month - 1][date.Day - 1].spentCat[i] != 0)
                cout << "You have spent " << viewDay[date.Month - 1][date.Day - 1].spentCat[i] << " on " << categories[i].cat_name << endl;
        cout << endl;
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
    else
    {
        cout << "Invalid choice number\n";
    }
        return;
}