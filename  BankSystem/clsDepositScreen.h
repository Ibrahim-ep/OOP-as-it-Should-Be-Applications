#pragma once

#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std;

class clsDepositScreen : protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName();
        cout << "\nLastName    : " << Client.LastName();
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email();
        cout << "\nPhone       : " << Client.Phone();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode();
        cout << "\nBalance     : " << Client.AccountBalance();
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        cout << "Pleas enter AccountNumber : ";
        string AccountNumber = clsInputValidate::ReadString();

        return AccountNumber;
    }

public:

    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t   Deposit Screen");
        
        string AccountNumber = _ReadAccountNumber();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient With [" << AccountNumber <<"] Not Found, Pleas enter another account number : ";
            AccountNumber = _ReadAccountNumber();
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "Pleas enter Deposit Amount : ";
        double Amount = clsInputValidate::ReadDblNumber();

       char AddAmount = 'n';

       cout << "Are you sure you want to do this transaction ? Y/N ? ";
       cin >> AddAmount;

       if (AddAmount == 'Y' || AddAmount == 'y')
       {
            Client1.Deposit(Amount);

            cout << "Transation done Successfully :-)\n";

            cout << "New Balance is : " << Client1.AccountBalance() << endl;
       }
       else
       {
            cout << "Operation was cancelled\n";
       }
    }
};