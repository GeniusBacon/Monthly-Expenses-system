#include <iostream>
#include <string>
#include "Wallet.h"

using namespace std;

void display();
void expandWallets();

int nextWallet = 0, Wallets_size=1;
Wallet* wallets=new Wallet[Wallets_size];
struct Date
{
    int Day;
    int Month;
    int Year;
};


int main()
{
    cout  << "\t\t\t\t\t" <<  "Welcome To" << endl;
    cout << "\t\t\t\t" << "Monthly Expenses Manager" << endl;
    
    display();
    return 0;
}


void display()
{
    int Choice;
    cout << "Please choose what you would like to do: \n\n";

    cout << "1-Create a new wallet\n";
    cout << "2-Add expense\n";
    cout << "3-Delete an existing wallet\n";
    cout << "\nPlease enter your choice number: ";

    cin >> Choice;
    system("CLS");
    if (Choice == 1)
    {
        if (nextWallet == Wallets_size)
            expandWallets();
        string name, password;
        double income;
        cout << "Please Enter Your Wallet Name: ";  cin >> name;
        cout << "Please Enter Your Password: ";  cin >> password;
        cout << "Please Enter Your income: ";  cin >> income;
        wallets[nextWallet].Initialize_Wallet(name, income);
        nextWallet++;
        cout << "\nYou have succesfully created a new wallet.\n\n";
        display();
    }
    else if (Choice == 2)
    {
        int Walletchoice;
        cout << "Please choose the wallet you spent from " << endl;
        for (int index=0; index < nextWallet; index++)
        {
            cout << index + 1 << ". " << wallets[index].wallet_Name << endl;
        }
        cin >> Walletchoice;
        Walletchoice--;
        system("CLS");

    }
    else if (Choice == 3)
    {
        //fn3()
    }
    else
    {
        cout << "\nInvalid choice number\n\n";
        system("CLS");
        display();
    }
}

void expandWallets()
{
    Wallets_size *= 2;
    Wallet* tmp = new Wallet[Wallets_size];
    for (int i = 0; i < Wallets_size / 2; i++)
        tmp[i] = wallets[i];
    delete []wallets;
    wallets = tmp;
}