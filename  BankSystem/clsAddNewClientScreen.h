#pragma once 

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"

class clsAddNewClientScreen : protected clsScreen
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
        Client.SetAccountBalance(AccountBalance);
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

    static void AddClient()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;
        }
        
        string AccountNumber;

        _DrawScreenHeader("\t   Add New Client Screen");

        cout << "Pleas enter client's account number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "account number already exist, Plaes enter another account number : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClient(AccountNumber);
    
        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nSave succeeded\n";

            _PrintClient(NewClient);

            break;
        }
        case clsBankClient::enSaveResults::svFailedAccountNumberExist:
        {
            cout << "\nSave Failed, Client already exist\n";
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