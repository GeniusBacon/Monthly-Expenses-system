#include "Wallet.h"
#include <string>
#include <iostream>

using namespace std;

Wallet::Wallet(void)
{

}

Wallet::Wallet(string name, string type, double income, double debt)
{
    walletName = name;
    Balance = income;
    walletType = type;
    Debt = debt;
    totalspent = 0;
}
// omar ezz :D

void Wallet::displayWalletMenu()
{
    cout << "\t\t\t\tHello, " << walletName << "\t\t Your balance is now " << Balance << "\t\tYour wallet Type: " << walletType << "\n\n";
    int Choice;
    cout << "Please choose what you would like to do: \n\n1- Add Expense\n2- Edit wallet\n3- View wallet expenses\n";
    cout << "4- Return to main menu\n\nPlease enter your choice number: ";
    cin >> Choice;
    cout << endl;
    if (Choice == 1)
        addExpense();
    else if (Choice == 2)
    {
        editWallet();
        system("CLS");
    }
    else if (Choice == 3)
    {
        viewWallet();
        system("CLS");
    }
    else if (Choice == 4)
    {
        system("CLS");
        return;
    }
    else cout << "\nInvalid choice number\n\n";
    displayWalletMenu();
}

void Wallet::addExpense()
{
    system("CLS");
    cout << "How much did you spend? ";
    double spent;
    cin >> spent;
    cout << endl;
    if (spent <= Balance)
    {
        cout << "Choose the category in which you spent your money, or 0 to go back & cancel expense.\nThe existing categories: \n\n";
        for (int i = 0; i < 9; i++)
            cout << i + 1 << ". " << categories[i] << endl;
        cout << "\nYour choice: ";
        int categChoice;
        cin >> categChoice;
        cout << endl;
        if (categChoice < 1 || categChoice>9)
        {
            if (categChoice != 0)           // 0 is used for going back.
                cout << "Invalid category number,returning to main menu...\n";
            return;
        }
        cout << "Please enter the Month that you spent this expense in, or 0 to go back & cancel expense.\nMonth: ";
        Date date;
        cin >> date.Month;
        cout << endl;
        if (date.Month > 12 || date.Month < 1)
        {
            if (date.Month != 0)        // 0 is used for going back. ....
                cout << "Wrong Month Input\n";
            return;
        }
        cout << "Please enter the Day that you spent this expense in, or 0 to go back & cancel expense.\nDay: ";
        cin >> date.Day;
        cout << endl;
        if ((date.Month==2 &&date.Day>28)||((date.Month==4|| date.Month==6|| date.Month==9|| date.Month==11)&&date.Day>30) || date.Day > 31 || date.Day < 1)
        {
            if (date.Day != 0)
                cout << "Wrong Day Input\n";
            return;
        }
        totalspent += spent;        // update the wallet total spending.
        Balance -= spent;
        if (categChoice == 7)
        {
            Debt -= spent;
            if (Debt < 0) Debt = 0;
            cout << "\nYour remaining debts are " << Debt << "\nYou need to save about " << ((Debt / Balance) * 100) << "% from your balance to pay all your debts.\n";
            cout << "\nType anything to continue.\n\n";
            string c; cin >> c;
        }
        Expenses.push_back({date, --categChoice, spent, walletName });
        system("CLS");
        cout << "Expense saved successfully.\n\n";
        return;
    }
    else if(spent>Balance)
        cout << "You don't have enough balance. This expense will be ignored.\n\n";   
    return ;
}

void Wallet::editWallet()       // function is on repeat until user returns to wallet menu. 
{
    system("CLS");
    cout << "The current wallet name is " << walletName << " and the current wallet balance is " << Balance << ".\n\n";
    int choice;
    cout << "Please choose what you would like to do: \n\n";
    cout << "1-Edit the wallet's name. \n";
    cout << "2-Edit the wallet's balance.\n";
    cout << "3-Edit the wallet's debts.\n";
    cout << "4-Return to Wallet menu.\n";
    cout << "\nPlease enter your choice number: ";
    cin >> choice;
    cout << endl;
    if (choice == 1)
    {
        cout << "\n Enter the new name: ";
        string name;
        cin >> name;
        walletName = name;
        cout << "\nEditing done successfully.\n\n";
    }
    else if (choice == 2)
    {
        cout << "\n Enter the new current balance: ";
        double balance;
        cin >> balance;
        if (balance <= 0)
        {
            cout << "Invalid balance is entered.\n";
            editWallet();
            return;
        }
        Balance = balance;
        cout << "\nEditing done successfully.\n\n";
    }
    else if (choice == 3)
    {
        cout << "\n Enter the new current debts: ";
        double debt;
        cin >> debt;
        if (debt <= 0)
        {
            cout << "Invalid debt is entered.\n";
            editWallet();
            return;
        }
        Debt = debt;
        cout << "\nEditing done successfully.\n\n";
    }
    else if (choice == 4) return;
    else cout << "\nInvalid choice number\n\n";

    cout << "\nType anything to continue.\n\n";
    string c; cin >> c;
    editWallet();
}

void Wallet::viewWallet()       // function is on repeat until user returns to wallet menu. 
{
    system("CLS");
    cout << "Your total spent money is: " << totalspent << "\n\nChoose how you want to filter your expenses:\n\n1- View All Expenses.\n2- Filter by date.\n3- ";
    cout << "Filter by category.\n4- Filter by amount of money.\n5- Filter by both date and category.\n6- Filter by both date and amount.\n";
    cout << "7- Filter by both category and amount.\n8- Filter by both date and amount and category.\n9- Return to Wallet menu.\n\nPlease enter your choice number: ";
    int choice;
    cin >> choice;
    cout << endl;
    if (choice == 1)
    {
        NoFilter();
    }
    else if (choice == 2)
        FilterByDate();
    else if (choice == 3)
        FilterByCat();
    else if (choice == 4)
        FilterByAmount();
    // add combined filters .
    else if (choice == 5)
        FilterByDateAndCategory();
    else if (choice == 6)
        FilterByDateAndAmount();
    else if (choice == 7)
        FilterByCategoryAndAmount();
    else if (choice == 8)
        FilterByDateAndAmountandCategory();
    else if (choice == 9) return;
    else cout << "Invalid choice number\n";
    viewWallet();
}

void Wallet::NoFilter()
{
    system("CLS");
    double total = 0;
    cout << " These are your expenses:\n\n";
    for (int i = 0; i < Expenses.size(); i++)
    {
        total += Expenses[i].amount;
        cout << "You have spent " << Expenses[i].amount << " on " << categories[Expenses[i].cat_id] << " In " << Expenses[i].date.Day << '/' << Expenses[i].date.Month << "\n";
    }
    if (total == 0)
    {
        cout << "You haven't Added any expenses yet.\n";
    }
    else {
        cout << "\nIn total, your expenses cost " << total << ".\n\n";
    }
    cout << "\nType anything to continue.\n\n";
    string c; cin >> c;
    system("CLS");
    return;
}

void Wallet::FilterByDate()
{
    system("CLS");
    Date date;
    cout << "Please enter the month you want to view, or 0 to go back.\nMonth: ";
    cin >> date.Month;
    cout << endl;
    if (date.Month > 12 || date.Month < 1)
    {
        if (date.Month != 0)
            cout << "Wrong Month Input\n";
        return;
    }
    cout << "Please enter the Day you want to view, or 0 to go back.\nDay: ";
    cin >> date.Day;
    cout << endl;
    if ((date.Month == 2 && date.Day > 28) || ((date.Month == 4 || date.Month == 6 || date.Month == 9 || date.Month == 11) && date.Day > 30) || date.Day > 31 || date.Day < 1)
    {
        if (date.Day != 0)
            cout << "Wrong Day Input\n";
        return;
    }
    double total=0;
    cout << "\nIn " << date.Day << '/' << date.Month << " These are your expenses:\n\n";
    
    for (int i = 0; i < Expenses.size(); i++)
        if (Expenses[i].date.Day == date.Day && Expenses[i].date.Month == date.Month)
        {
            total += Expenses[i].amount;
            cout << "You have spent " << Expenses[i].amount << " on " << categories[Expenses[i].cat_id] << endl;
        }
       
    if (total == 0)
    {
        cout << "You didn't Add any expenses yet.\n";
    }
    else {
        cout << "\nIn total, your expenses cost " << total << ".\n\n";
    }
    cout << "\nType anything to continue.\n\n";
    string c; cin >> c;
    return;
}

void Wallet::FilterByCat()
{
    system("CLS");
    int categChoice;
    cout << "Choose the category by which you want to filter your expenses, or 0 to go back.\nThe existing categories: \n\n";
    for (int i = 0; i < 9; i++)
        cout << i + 1 << ". " << categories[i] << endl;
    cin >> categChoice;
    cout << endl;
    if (categChoice < 1 || categChoice>9)
    {
        if (categChoice != 0)
            cout << "Invalid category number,returning to main menu...\n";
        return;
    }
    double total = 0;
    cout << "\nOn " << categories[--categChoice] << ", These are your expenses:\n\n";
    for (int i = 0; i < Expenses.size(); i++)
        if (categChoice == Expenses[i].cat_id)
        {
            total += Expenses[i].amount;
            cout << "You have spent " << Expenses[i].amount  << " in " << Expenses[i].date.Day << '/' << Expenses[i].date.Month << endl;
        }
    if (total == 0)
    {
        cout << "You didn't Add any expenses yet.\n";
    }
    else {
        cout << "\nIn total, your expenses cost " << total << ".\n\n";
    }
    cout << "\nType anything to continue.\n\n";
    string c; cin >> c;
    return;
}

void Wallet::FilterByAmount()
{
    system("CLS");
    cout << "Enter the amount of money to filter by, or 0 to go back.\n";
    double amount;
    cin >> amount;
    cout << endl;
    if (amount <= 0)
    {
        if (amount != 0)
            cout << "The amount't can't be negative.\n";
        return;
    }
    cout << "\nWith " << amount << ", These are your expenses:\n\n";
    double total = 0;
    for (int i = 0; i < Expenses.size(); i++)
        if (amount == Expenses[i].amount)
        {
            total += amount;
            cout << "In " << Expenses[i].date.Day << '/' << Expenses[i].date.Month << " and on "
                << categories[Expenses[i].cat_id] << "\n\n";
        }
    if (total == 0)
    {
        cout << "You didn't Add any expenses yet.\n";
    }
    else {
        cout << "\nIn total, your expenses cost " << total << ".\n\n";
    }
    cout << "\nType anything to continue.\n\n";
    string c; cin >> c;
    return;
}

void Wallet::FilterByDateAndCategory()
{
    system("CLS");
    Date date;
    cout << "Please enter the month you want to view, or 0 to go back.\nMonth: ";
    cin >> date.Month;
    cout << endl;
    if (date.Month > 12 || date.Month < 1)
    {
        if (date.Month != 0)
            cout << "Wrong Month Input\n";
        return;
    }
    cout << "Please enter the Day you want to view, or 0 to go back.\nDay: ";
    cin >> date.Day;
    cout << endl;
    if ((date.Month == 2 && date.Day > 28) || ((date.Month == 4 || date.Month == 6 || date.Month == 9 || date.Month == 11) && date.Day > 30) || date.Day > 31 || date.Day < 1)
    {
        if (date.Day != 0)
            cout << "Wrong Day Input\n";
        return;
    }
    int categChoice;
    cout << "Choose the category by which you want to filter your expenses, or 0 to go back.\nThe existing categories: \n\n";
    for (int i = 0; i < 9; i++)
        cout << i + 1 << ". " << categories[i] << endl;
    cin >> categChoice;
    cout << endl;
    if (categChoice < 1 || categChoice>9)
    {
        if (categChoice != 0)
            cout << "Invalid category number,returning to main menu...\n";
        return;
    }
    double total = 0;
    cout << "\nOn " << categories[--categChoice] << " , In " << date.Day << '/' << date.Month << ", These are your expenses:\n\n";
    for (int i = 0; i < Expenses.size(); i++)
        if (categChoice == Expenses[i].cat_id && Expenses[i].date.Day == date.Day && Expenses[i].date.Month == date.Month)
        {
            total += Expenses[i].amount;
            cout << "You have spent " << Expenses[i].amount << endl;
        }
    if (total == 0)
    {
        cout << "You didn't Add any expenses yet.\n";
    }
    else {
        cout << "\nIn total, your expenses cost " << total << ".\n\n";
    }
    cout << "\nType anything to continue.\n\n";
    string c; cin >> c;
    return;
}

void Wallet::FilterByDateAndAmount()
{
    system("CLS");
    Date date;
    cout << "Please enter the month you want to view, or 0 to go back.\nMonth: ";
    cin >> date.Month;
    cout << endl;
    if (date.Month > 12 || date.Month < 1)
    {
        if (date.Month != 0)
            cout << "Wrong Month Input\n";
        return;
    }
    cout << "Please enter the Day you want to view, or 0 to go back.\nDay: ";
    cin >> date.Day;
    cout << endl;
    if ((date.Month == 2 && date.Day > 28) || ((date.Month == 4 || date.Month == 6 || date.Month == 9 || date.Month == 11) && date.Day > 30) || date.Day > 31 || date.Day < 1)
    {
        if (date.Day != 0)
            cout << "Wrong Day Input\n";
        return;
    }
    cout << "Enter the amount of money to filter by, or 0 to go back.\n";
    double amount;
    cin >> amount;
    cout << endl;
    if (amount <= 0)
    {
        if (amount != 0)
            cout << "The amount can't be negative.\n";
        return;
    }
    double total = 0;
    cout << "In " << date.Day << '/' << date.Month << " With " << amount << ", These are your expenses:\n\n";
    for (int i = 0; i < Expenses.size(); i++)
        if ( Expenses[i].date.Day == date.Day && Expenses[i].date.Month == date.Month && amount == Expenses[i].amount)
        {
            total += Expenses[i].amount;
            cout << "You have spent " << Expenses[i].amount << " on " << categories[Expenses[i].cat_id] << endl;
        }
    if (total == 0)
    {
        cout << "You didn't Add any expenses yet.\n";
    }
    else {
        cout << "\nIn total, your expenses cost " << total << ".\n\n";
    }
    cout << "\nType anything to continue.\n\n";
    string c; cin >> c;
    return;
}

void Wallet::FilterByCategoryAndAmount()
{
    system("CLS");
    int categChoice;
    cout << "Choose the category by which you want to filter your expenses, or 0 to go back.\nThe existing categories: \n\n";
    for (int i = 0; i < 9; i++)
        cout << i + 1 << ". " << categories[i] << endl;
    cin >> categChoice;
    cout << endl;
    if (categChoice < 1 || categChoice>9)
    {
        if (categChoice != 0)
            cout << "Invalid category number,returning to main menu...\n";
        return;
    }
    cout << "Enter the amount of money to filter by, or 0 to go back.\n";
    double amount;
    cin >> amount;
    cout << endl;
    if (amount <= 0)
    {
        if (amount != 0)
            cout << "The amount can't be negative.\n";
        return;
    }
    double total = 0;
    cout << "\nOn " << categories[--categChoice] << ", With " << amount << ", These are your expenses:\n\n";
    for (int i = 0; i < Expenses.size(); i++)
        if (categChoice == Expenses[i].cat_id && amount == Expenses[i].amount)
        {
            total += Expenses[i].amount;
            cout << "You have spent " << Expenses[i].amount << " In " << Expenses[i].date.Day << '/' << Expenses[i].date.Month << endl;
        }
    if (total == 0)
    {
        cout << "You didn't Add any expenses yet.\n";
    }
    else {
        cout << "\nIn total, your expenses cost " << total << ".\n\n";
    }
    cout << "\nType anything to continue.\n\n";
    string c; cin >> c;
}

void Wallet::FilterByDateAndAmountandCategory()
{
    system("CLS");
    Date date;
    cout << "Please enter the month you want to view, or 0 to go back.\nMonth: ";
    cin >> date.Month;
    cout << endl;
    if (date.Month > 12 || date.Month < 1)
    {
        if (date.Month != 0)
            cout << "Wrong Month Input\n";
        return;
    }
    cout << "Please enter the Day you want to view, or 0 to go back.\nDay: ";
    cin >> date.Day;
    cout << endl;
    if ((date.Month == 2 && date.Day > 28) || ((date.Month == 4 || date.Month == 6 || date.Month == 9 || date.Month == 11) && date.Day > 30) || date.Day > 31 || date.Day < 1)
    {
        if (date.Day != 0)
            cout << "Wrong Day Input\n";
        return;
    }
    int categChoice;
    cout << "Choose the category by which you want to filter your expenses, or 0 to go back.\nThe existing categories: \n\n";
    for (int i = 0; i < 9; i++)
        cout << i + 1 << ". " << categories[i] << endl;
    cin >> categChoice;
    cout << endl;
    if (categChoice < 1 || categChoice>9)
    {
        if (categChoice != 0)
            cout << "Invalid category number,returning to main menu...\n";
        return;
    }
    cout << "Enter the amount of money to filter by, or 0 to go back.\n";
    double amount;
    cin >> amount;
    cout << endl;
    if (amount <= 0)
    {
        if (amount != 0)
            cout << "The amount can't be negative.\n";
        return;
    }
    double total = 0;
    cout << "In " << date.Day << '/' << date.Month << " With " << amount << " On " << categories[--categChoice] << ", These are your expenses:\n\n";
    for (int i = 0; i < Expenses.size(); i++)
        if (Expenses[i].date.Day == date.Day && Expenses[i].date.Month == date.Month && amount == Expenses[i].amount && categChoice == Expenses[i].cat_id)
        {
            total += Expenses[i].amount;
            cout << "You have spent " << Expenses[i].amount << " on " << categories[Expenses[i].cat_id] << endl;
        }
    if (total == 0)
    {
        cout << "You didn't Add any expenses yet.\n";
    }
    else {
        cout << "\nIn total, your expenses cost " << total << ".\n\n";
    }
    cout << "\nType anything to continue.\n\n";
    string c; cin >> c;
    return;
}