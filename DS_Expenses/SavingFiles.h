#include "Wallet.h"
#include <string>
#include <vector>
using namespace std;


class SavingFiles
{

public:

	
	void add_Wallet_to_file(vector<Wallet>);
	void add_Expense_to_file(vector<Expense>);
	void read_Expense_from_File(vector<Expense>&,string);
	void read_Wallets_from_Files(vector<Wallet>&);
};