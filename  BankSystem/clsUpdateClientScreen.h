#pragma once

#include <iostream>
#include "clsScreen.h" 
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsUpdateCleintScreen : protected clsScreen
{
private:

    static void _ReadClientInfo(clsBankClient &Client)
    {
        string FirstName, LastName, Email, Pincode, Phone;
        float AccountBalance;

        cout << "\nEnter First Name : ";
        FirstName = clsInputValidate::ReadString();
        Client.SetFirstName(FirstName);

        cout << "\nEnter Last Name : ";
        LastName = clsInputValidate::ReadString();
        Client.SetLastName(LastName);

        cout << "\nEnter E-mail : ";
        Email = clsInputValidate::ReadString();
        Client.SetEmail(Email);

        cout << "\nEnter Phone Number : ";
        Phone = clsInputValidate::ReadString();
        Client.SetPhone(Phone);

        cout << "\nEnter PIN Code : ";
        Pincode = clsInputValidate::ReadString();
        Client.setPinCode(Pincode);

        cout << "\nEnter Account Balance : ";
        AccountBalance = clsInputValidate::ReadDblNumber();
    }

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

public:

    static void UpdateClientScreen()
    {   
        _DrawScreenHeader("\t   Update Client Screen");

        string AccountNumber;

        cout << "Pleas enter client's account number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "account number not found, Plaes enter another account number : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout << "\n\nUpdate Client Info :\n";
        cout << "-------------------------\n";

        _ReadClientInfo(Client1);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nSave succeeded\n";

            _PrintClient(Client1);

            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nSave Failed, Object was empty\n";
            break;
        }
        }
    }

};