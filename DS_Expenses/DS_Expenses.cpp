#include <iostream>
#include <vector>
#include <string>
#include "Wallet.h"

using namespace std;

void display();
void printWallets();
void createWallet();
void addExpense();
void editWallet();
void deleteWallet();

int nextWallet = 0;
vector <Wallet> wallets;

int main()
{
    cout << "\t\t\t\t\t\t\t" << "Welcome To" << endl;
    cout << "\t\t\t\t\t\t" << "Monthly Expenses Manager" << endl;

    display();
    return 0;
}


void display()
{
    int Choice;
    cout << "Please choose what you would like to do: \n\n";
    cout << "1-Create a new wallet\n";
    cout << "2-Add Expense\n";
    cout << "3-Edit an existing wallet\n";
    cout << "4-Delete an existing wallet\n";
    cout << "5-Terminate The Program\n ";
    cout << "\nPlease enter your choice number: ";

    cin >> Choice;
    system("CLS");
    if (Choice == 1)
    {
        createWallet();
    }
    else if (Choice == 2)
    {
        addExpense();
    }
    else if (Choice == 3)
    {
        editWallet();
    }
    else if (Choice == 4)
    {
        deleteWallet();
    }
    else if (Choice == 5)
    {
        cout<<"\t\t\t\t\t\t Goodbye :)  \n \n \n ";
        return  ;
    }
    else
    {
        cout << "\nInvalid choice number\n\n";
        system("CLS");
        display();
    }
}

void printWallets()
{
    for (int index = 0; index < nextWallet; index++)
        cout << index + 1 << ". " << wallets[index].wallet_Name << "\t Current balance: " << wallets[index].Balance << endl;
}
void createWallet()
{
    string name;
    double income;
    cout << "Please Enter Your Wallet Name: ";  cin >> name;
    cout << "Please Enter Your income: ";  cin >> income;
    Wallet* tmp = new Wallet(name, income);
    wallets.push_back(*tmp);
    delete tmp;
    nextWallet++;
    cout << "\nYou have succesfully created a new wallet.\n\n";
    display();
}

void addExpense()
{
    cout << "Please choose the wallet you spent from " << endl;
    printWallets();
    int Walletchoice;
    cin >> Walletchoice;
    Walletchoice--;
    cout << "Your current balance: " << wallets[Walletchoice].Addexpense() << endl;
}

void editWallet()
{
    cout << "Please choose the wallet you want to edit: " << endl;
    
    printWallets();
    int Walletchoice;
    cin >> Walletchoice;
    Walletchoice--;
    wallets[Walletchoice].editWallet();
   
}

void deleteWallet()
{
    cout << "Please choose the wallet you want to delete : " << endl;
    printWallets();
    int Walletchoice;
    cin >> Walletchoice;
    Walletchoice--;
    wallets.erase(wallets.begin() + Walletchoice);
    cout << "\n\nYou have succesfully deleted the wallet.\n\n";
    system("CLS");
}