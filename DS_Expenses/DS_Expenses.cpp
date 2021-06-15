#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include "Wallet.h"
#include "SavingFiles.h"
using namespace std;

void displayMainMenu();
void createWallet();
void deleteWallet();
int callWallet();
void Send_Wallets_To_File();
void Read_From_Files();
vector <Wallet> wallets;
map<string,bool>nameExists;
SavingFiles File_Stream;

int main()
{
    Read_From_Files();
    cout << "\t\t\t\t\t\t\t" << "Welcome To" << "\n\t\t\t\t\t\t" << "Monthly Expenses Manager\n";
    displayMainMenu();  // main menu that is on loop until the user terminates the program.
    return 0;
}

void displayMainMenu()
{
    cout << "\nPlease choose what you would like to do: \n\n1- Create a new wallet\n2- Enter a wallet\n3- Delete an existing wallet\n";
    cout << "4- Terminate The Program\n\nPlease enter your choice number: ";

    int Choice;
    cin >> Choice;
    system("CLS");
    if (Choice == 1)
        createWallet();
    else if (Choice == 2)
    {
        int ret = callWallet();
        if (ret != -1)          // invalid wallet number.
        {
            system("CLS");
            wallets[ret].displayWalletMenu();   // wallet menu that is on loop until the user returns to main menu.
        }
    }
    else if (Choice == 3)
        deleteWallet();
    else if (Choice == 4)
    {
        Send_Wallets_To_File();
        cout << "\n\n\t\t\t\t\t\t Goodbye :)  \n \n \n ";
        return;
    }
    else
    {
        cout << "\nInvalid choice number\n\n";
        system("CLS");
    }
        displayMainMenu();      // repeat main menu
        return;
}

void createWallet()
{
    string name;
    double income;
    cout << "Please Enter Your Wallet Name: ";
    cin.ignore();
    getline(cin, name);
    if (nameExists[name] == 1) 
    {
       cout << "Name already exists.Try Again.\n";
        return;
    }
    nameExists[name] = 1;
    cout << "Please Enter Your income: ";  
    cin >> income;
    if (income <= 0) 
    {
        cout << "Invalid balance is entered.\n";
        return;
    }
    Wallet* tmp = new Wallet(name, income);
    wallets.push_back(*tmp);
    delete tmp;
    cout << "\nYou have succesfully created a new wallet.\n\n";
}

void deleteWallet()
{
    int ret = callWallet();
    if (ret != -1)
    {
        nameExists[wallets[ret].getName()]=0;
        wallets.erase(wallets.begin() + ret);
        cout << "\n\nYou have succesfully deleted the wallet.\n\n";
    }
}

int callWallet()        // takes wallet choice from user.
{
    if (wallets.empty())
    {
        cout << "\nThere are no existing wallets! \n\n";
        return -1;
    }
    cout << "Please choose the number of the wallet you want, or 0 to go back. \nThese are the existing wallets: \n\n";
    for (int index = 0; index < wallets.size(); index++)
        cout << index + 1 << ". " << wallets[index].getName() << endl;
    cout << "\nYour choice: ";
    int Walletchoice;
    cin >> Walletchoice;
    cout << endl;
    if (Walletchoice == 0) return -1;       // user goes back.
    Walletchoice--;
    if (Walletchoice >= wallets.size() || Walletchoice < 0)
    {
        cout << "Wallet doesn't exist\n\n";
        return -1;
    }
    return Walletchoice;
}
void Send_Wallets_To_File()
{   
    File_Stream.add_Wallet_to_file(wallets);
}
void Read_From_Files()
{
    File_Stream.read_Wallets_from_Files(wallets);

}