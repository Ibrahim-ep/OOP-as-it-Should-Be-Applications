#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std;

class clsTransferScreen : protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance();
        cout << "\n___________________\n";
    }

    static string _ReadTransferFromAccountNumber()
    {
        string AccountNumber;

        cout << "\nPlease Enter Account Number to Transfer From: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        return AccountNumber;
    }

    static string _ReadTransferToAccountNumber()
    {
        string AccountNumber;

        cout << "\nPlease Enter Account Number to Transfer To: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        return AccountNumber;
    }
    
    static float _ReadAmount(clsBankClient SourceClient)
   {
       float Amount;

       cout << "\nEnter Transfer Amount? ";

       Amount = clsInputValidate::ReadFloatNumber();

       while (Amount > SourceClient.AccountBalance())
       {
           cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
           Amount = clsInputValidate::ReadDblNumber();
       }
       return Amount;
   }

public:

    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t   Transfer Screen");
        
        clsBankClient SourceClient = clsBankClient::Find(_ReadTransferFromAccountNumber());
        _PrintClient(SourceClient);
        
        clsBankClient DestinationClient = clsBankClient::Find(_ReadTransferToAccountNumber());
        _PrintClient(DestinationClient);

        cout << "Pleas enter Transfer Amount : ";
        double Amount = _ReadAmount(SourceClient);

        char AddAmount = 'n';

        cout << "Are you sure you want to do this transaction ? Y/N ? ";
        cin >> AddAmount;

        if (AddAmount == 'y' || AddAmount == 'Y')
        {
           
            if (SourceClient.Transfer(Amount,DestinationClient,CurrentUser.UserName()))
            {
                cout << "\n\nTransfer Done Successfully" << endl;
            }
            else
            {
                cout << "\n\nTransfer Failed" << endl;
            }

            _PrintClient(SourceClient);
            _PrintClient(DestinationClient);
        }
    }
};