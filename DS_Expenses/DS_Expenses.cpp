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
void multipleWallet();
void remainingMoney();
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
    cout << "4- View expenses for multiple Wallets.\n5- View remaining money for all Wallets.\n6- Terminate The Program\n\nPlease enter your choice number: ";

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
        multipleWallet();
    else if (Choice == 5)
        remainingMoney();
    else if (Choice == 6)
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
    string name, type;
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
    cout << "\nPlease Enter The number of Your Wallet Type:\n1- Cash.\n2- Debit Card.\n3- Credit Card.\n";
    int choice; 
    cout << "\nYour choice: ";
    cin >> choice;
    if (choice == 1)
        type = "Cash";
    else if(choice == 2)
        type = "Debit-Card";
    else if (choice == 3)
        type = "Credit-Card";
    else 
    {
        cout << "Invaid choice.\n";
        return;
    }
    cout << "\nPlease Enter Your income: ";  
    cin >> income;
    if (income <= 0) 
    {
        cout << "Invalid balance is entered.\n";
        return;
    }
    cout << "Enter your debts (if you have) : ";
    double d;
    cin >> d;
    wallets.push_back({name, type, income, d});
    cout << "\nYou have succesfully created a new wallet.\n\n";
}

void deleteWallet()
{
    int ret = callWallet();
    if (ret != -1)
    {
        nameExists[wallets[ret].walletName]=0;
        wallets.erase(wallets.begin() + ret);
        cout << "\n\nYou have succesfully deleted the wallet.\n\n";
    }
}

void multipleWallet()
{
    if (wallets.empty())
    {
        cout << "\nThere are no existing wallets! \n\n";
        return ;
    }
    for (int index = 0; index < wallets.size(); index++)
        cout << index + 1 << ". " << wallets[index].walletName << "\t" << wallets[index].walletType << "\n\n";
    cout << "\nHow many wallets do you want to display? ";
    int n;
    cin >> n;
    if (n > wallets.size())
    {
        cout << "Wrong Input, The number you wrote may exceede the existing wallets size"<<endl;
        
        multipleWallet();
    }
    map<int, bool> view;
    system("CLS");
    for (int i = 0; i < n; i++)
    {
        int num;
        cout << "Enter the number of wallet number " << i + 1 << ": ";
        cin >> num;
        if (num > wallets.size() || num <1)
        {
            cout << "Wrong Input,Please write the correct wallet number"<<endl;
            multipleWallet();
        }
        view[num - 1] = 1;
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < wallets.size(); i++)
    {
        if (view[i] == 1)
        {
            cout << "From " << wallets[i].walletName << "\t" << wallets[i].walletType << ":\n";
            wallets[i].NoFilter();
        }
    }
    return;
}

void remainingMoney()
{
    if (wallets.empty())
    {
        cout << "\nThere are no existing wallets! \n\n";
        return ;
    }
    for (int i = 0; i < wallets.size(); i++)
        cout << "The remaining money for " << wallets[i].walletName << " / " << wallets[i].walletType << " is " << wallets[i].Balance << endl;
    cout << endl;
    return;
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
        cout << index + 1 << ". " << wallets[index].walletName << "          " << wallets[index].walletType << "\n\n";
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