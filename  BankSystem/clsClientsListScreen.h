#pragma once

#include <iostream>
#include"clsBankClient.h"
#include <iomanip>
#include "clsScreen.h"

class clsClientsListScreen : protected clsScreen
{
    private:

    static void PrintClientRecordLine(clsBankClient Client)
    {
        cout << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone();
        cout << "| " << setw(20) << left << Client.Email();
        cout << "| " << setw(10) << left << Client.PinCode();
        cout << "| " << setw(12) << left << Client.AccountBalance();
    }

    public:

    static void ShowClientsList()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pListClients))
        {
            return;
        }

        vector <clsBankClient> vClient = clsBankClient::GetClientsList();

        string Title = "\t   Clients List Screen";
        string SubTitle = "\t   (" + to_string(vClient.size()) +") Client(s)";

        clsScreen::_DrawScreenHeader(Title,SubTitle);

        cout << setw(8) << left << "" << "\n--------------------------------------------------------------";
        cout << "--------------------------------------------\n";
        cout << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(20) << "Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "E-mail";
        cout << "| " << left << setw(10) << "PIN code"; 
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
                PrintClientRecordLine(c);
                cout << endl;
            }
        
        }
        cout << "\n--------------------------------------------------------------";
        cout << "--------------------------------------------\n";
    }

};