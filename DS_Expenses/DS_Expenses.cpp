#include <iostream>
#include <vector>
#include <string>
#include "Wallet.h"

using namespace std;

void display();
void printWallets();

int nextWallet = 0;
vector <Wallet> wallets;
struct Date
{
    int Day;
    int Month;
    int Year;
};


int main()
{
    cout  << "\t\t\t\t\t\t\t" <<  "Welcome To" << endl;
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
    cout << "3-Edit an existing wallet\n";
    cout << "4-Delete an existing wallet\n";
    cout << "\nPlease enter your choice number: ";

    cin >> Choice;
    system("CLS");
    if (Choice == 1)
    {
        string name;
        double income;
        cout << "Please Enter Your Wallet Name: ";  cin >> name;
        cout << "Please Enter Your income: ";  cin >> income;
        Wallet *tmp = new Wallet(name, income);
        wallets.push_back(*tmp);
        delete tmp;
        nextWallet++;
        cout << "\nYou have succesfully created a new wallet.\n\n";
        display();
    }
    else if (Choice == 2)
    {
        cout << "Please choose the wallet you spent from " << endl;
        printWallets();
        int Walletchoice;
        cin >> Walletchoice;
        Walletchoice--;
        // to be continued
        system("CLS");

    }
    else if (Choice == 3)
    {
        cout << "Please choose the wallet you want to edit: " << endl;
        printWallets();
        int Walletchoice, choice;
        cin >> Walletchoice;
        Walletchoice--;
        cout << "Please choose what you would like to do: \n\n";
        cout << "1-Edit the wallet's name. \n";
        cout << "2-Edit the wallet's balance.\n";
        cin >> choice;
        if (choice == 1)
        {
            cout << "\n Enter the new name: ";
            string name;
            cin >> name;
            wallets[Walletchoice].wallet_Name = name;
            cout << "Editing done successfully.\n";
        }
        else if (choice == 2)
        {
            cout << "\n Enter the new current balance: ";
            int balance;
            cin >> balance;
            wallets[Walletchoice].Income = balance;
        }
        else cout << "\nInvalid choice number\n\n";
        system("CLS");

    }
    else if (Choice == 4)
    {
        cout << "Please choose the wallet you want to delete : " << endl;
        printWallets();
        int Walletchoice; 
        cin >> Walletchoice;
        Walletchoice--;
        wallets.erase(wallets.begin()+ Walletchoice);
        cout << "\n\nYou have succesfully deleted the wallet.\n\n";
        system("CLS");
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
        cout << index + 1 << ". " << wallets[index].wallet_Name << "\t Current balance: " << wallets[index].Income << endl;
}
