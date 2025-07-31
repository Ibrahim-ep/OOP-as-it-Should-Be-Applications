#include <iostream>
#include "clsUtil.h"
#include "clsMainScreen.h"

using namespace std;

void PrintClientRecordBalanceLine(clsBankClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber();
    cout << "| " << setw(40) << left << Client.FullName();
    cout << "| " << setw(12) << left << Client.AccountBalance();
}

void ShowBalancesList()
{
    vector <clsBankClient> vClient = clsBankClient::GetClientsList();

    cout << "\n\t\t\t\t\tBalances List (" << vClient.size() <<") Client(s)\n";
    cout << "\n--------------------------------------------------------------";
    cout << "--------------------------------------------\n";
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(40) << "Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n--------------------------------------------------------------";
    cout << "--------------------------------------------\n";

    if (vClient.size() == 0)
    {
        cout << "\t\t\t\tNo Clients Available in the system!";
    }
    else
    {
        for (clsBankClient &c : vClient)
        {
            PrintClientRecordBalanceLine(c);
            cout << endl;
        }
        
    }
    cout << "\n--------------------------------------------------------------";
    cout << "--------------------------------------------\n";

    double TotalBalances = clsBankClient::GetTotalBalances();

    cout << "\t\t\t\t\tTotal Balances : ("<< TotalBalances<<")" << endl;
    cout << "\t\t\t\t\t("<< clsUtil::NumberToText(TotalBalances) <<")" << endl;
}

int main()
{   

    clsMainScreen::ShowMainMenue();

    return 0;
}