#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsBankClient.h"

using namespace std;

class clsTransferLogScreen : protected clsScreen
{
private:

    static void _PrintUserRegisterRecordLine(clsBankClient::stTransferLogRecord Client)
    {
        cout << setw(8) << left << "" << "| " << setw(35) << left << Client.Date;
        cout << "| " << setw(10) << left << Client.SourceAccountNumber;
        cout << "| " << setw(10) << left << Client.DestinationAccountNumber;
        cout << "| " << setw(10) << left << Client.Amount;
        cout << "| " << setw(10) << left << Client.SourceBalance;
        cout << "| " << setw(10) << left << Client.DestinationBalance;
        cout << "| " << setw(10) << left << Client.Username;
    }

public:

    static void ShowTransferLogScreen()
    {
        vector <clsBankClient::stTransferLogRecord> vClient = clsBankClient::GetTransferLogList();

        string Title = "\t  Transfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vClient.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(10) << "S.Acc";
        cout << "| " << left << setw(10) << "D.Acc";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "S.Balance";
        cout << "| " << left << setw(10) << "D.Balance";
        cout << "| " << left << setw(10) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vClient.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord &Client : vClient)
            {

                _PrintUserRegisterRecordLine(Client);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }
};