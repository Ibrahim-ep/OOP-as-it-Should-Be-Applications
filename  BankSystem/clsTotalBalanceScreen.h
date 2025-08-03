#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include <iomanip>

using namespace std;

class clsTotalBalanceScreen : protected clsScreen
{
private:

    static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance();
    }
public:

    static void ShowBalancesList()
    {
        vector <clsBankClient> vClient = clsBankClient::GetClientsList();
        
        string Title ="\t   Total Balances Screen";
        string SubTitle = "\t   ("+ to_string(vClient.size()) +")";

        _DrawScreenHeader(Title,SubTitle);

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
                _PrintClientRecordBalanceLine(c);
                cout << endl;
            }

        }
        cout << "\n--------------------------------------------------------------";
        cout << "--------------------------------------------\n";

        double TotalBalances = clsBankClient::GetTotalBalances();

        cout << "\t\t\t\t\tTotal Balances : ("<< TotalBalances<<")" << endl;
        cout << "\t\t\t\t\t("<< clsUtil::NumberToText(TotalBalances) <<")" << endl;
    }
};