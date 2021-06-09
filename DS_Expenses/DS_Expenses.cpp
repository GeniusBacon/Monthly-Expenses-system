#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include "Wallet.h"

using namespace std;

int display();
void printWallets();
void createWallet();
void deleteWallet();
int callWallet();

int nextWallet = 0;
vector <Wallet> wallets;

int main()
{
    cout << "\t\t\t\t\t\t\t" << "Welcome To" << endl;
    cout << "\t\t\t\t\t\t" << "Monthly Expenses Manager" << endl;
    display();
    return 0;
}


int display()
{
    int Choice;
    cout << "Please choose what you would like to do: \n\n";
    cout << "1-Create a new wallet\n";
    cout << "2-Add Expense\n";
    cout << "3-Edit an existing wallet\n";
    cout << "4-Delete an existing wallet\n";
    cout << "5-View the expenses of an existing wallet\n";
    cout << "6-Terminate The Program\n ";
    cout << "\nPlease enter your choice number: ";

    cin >> Choice;
    system("CLS");
    if (Choice == 1)
        createWallet();
    else if (Choice == 2)
    {
        cout << "Please choose the wallet you spent from " << endl;
        int ret = callWallet();
        if (ret >= 0)
            wallets[ret].Addexpense();
    }
    else if (Choice == 3)
    {
        cout << "Please choose the wallet you want to edit: " << endl;
        int ret = callWallet();
        if (ret >= 0)
            wallets[ret].editWallet();
    }
    else if (Choice == 4)
        deleteWallet();
    else if (Choice == 5)
    {
        cout << "Please choose the wallet you want to view: " << endl;
        int ret = callWallet();
        if (ret >= 0)
            wallets[ret].viewWallet();
    }
    else if (Choice == 6)
        return cout << "\t\t\t\t\t\t Goodbye :)  \n \n \n ", 0;
    else
    {
        cout << "\nInvalid choice number\n\n";
        system("CLS");
    }
        display();
}

void printWallets()
{
    for (int index = 0; index < nextWallet; index++)
        cout << index + 1 << ". " << wallets[index].walletName << "\t Current balance: " << wallets[index].Balance << endl;
}
void createWallet()
{
    string name;
    double income;
    cout << "Please Enter Your Wallet Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Please Enter Your income: ";  cin >> income;
    Wallet* tmp = new Wallet(name, income);
    wallets.push_back(*tmp);
    delete tmp;
    nextWallet++;
    cout << "\nYou have succesfully created a new wallet.\n\n";
    
}

void deleteWallet()
{
    cout << "Please choose the wallet you want to delete : " << endl;
    printWallets();
    int Walletchoice;
    cin >> Walletchoice;
    if (Walletchoice > nextWallet)
    {
        cout << "Wallet doesn't exist  \n   ";
        return;
    }
    Walletchoice--;
    wallets.erase(wallets.begin() + Walletchoice);
    cout << "\n\nYou have succesfully deleted the wallet.\n\n";
    system("CLS");
}

int callWallet()
{
    printWallets();
    int Walletchoice;
    cin >> Walletchoice;
    Walletchoice--;
    if (Walletchoice >= nextWallet || Walletchoice < 0)
    {
        cout << "Wallet doesn't exist  \n   ";
        return -1;
    }
    return Walletchoice;
}