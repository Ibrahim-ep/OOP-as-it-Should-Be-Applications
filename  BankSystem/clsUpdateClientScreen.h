#pragma once

#include <iostream>
#include "clsScreen.h" 
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <string>

class clsUpdateCleintScreen : protected clsScreen
{
private:

    static void _ReadClientInfo(clsBankClient &Client)
    {
       string Input;
       double dInput;

        cout << "\nEnter First Name : ";
        Input = clsInputValidate::ReadStringAndUpperFirstLetter();

        if (Input != "Skip")
        {
            Client.SetFirstName(Input);
        }

        cout << "\nEnter Last Name : ";
        Input = clsInputValidate::ReadStringAndUpperFirstLetter();

        if (Input != "Skip")
        {
            Client.SetLastName(Input);
        }

        cout << "\nEnter E-mail : ";
        Input = clsInputValidate::ReadStringAndUpperFirstLetter();

        if (Input != "Skip")
        {
            Client.SetEmail(Input);
        }

        cout << "\nEnter Phone Number : ";
        Input = clsInputValidate::ReadStringAndUpperFirstLetter();

        if (Input != "Skip")
        {
            Client.SetPhone(Input);
        }

        cout << "\nEnter PIN Code : ";
        Input = clsInputValidate::ReadStringAndUpperFirstLetter();

        if (Input != "Skip")
        {
            Client.setPinCode(Input);
        }
       
        

        cout << "\nEnter Account Balance : ";
        Input = clsInputValidate::ReadStringAndUpperFirstLetter();

        if (Input != "Skip")
        {
            Client.SetAccountBalance(stod(Input));
        }
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
        
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;
        }

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
        cout << "If you don't want to change anythin enter Skip!\n";
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