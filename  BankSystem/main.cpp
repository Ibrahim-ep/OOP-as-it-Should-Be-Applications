#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

void ReadClientInfo(clsBankClient &Client)
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

void UpdateClient()
{
    string AccountNumber;

    cout << "Pleas enter client's account number : ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "account number not found, Plaes enter another account number : ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    cout << "\n\nUpdate Client Info :\n";
    cout << "-------------------------\n";

    ReadClientInfo(Client1);

    clsBankClient::enSaveResults SaveResult;

    SaveResult = Client1.Save();

    switch (SaveResult)
    {
    case clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nSave succeeded\n";

        Client1.Print();

        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nSave Failed, Object was empty\n";
        break;
    }
    }
}

void AddClient()
{
    string AccountNumber;

    cout << "Pleas enter client's account number : ";
    AccountNumber = clsInputValidate::ReadString();

    while (clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "account number already exist, Plaes enter another account number : ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient NewClient = clsBankClient::GetAddNewClient(AccountNumber);
    
    ReadClientInfo(NewClient);

    clsBankClient::enSaveResults SaveResult;

    SaveResult = NewClient.Save();

    switch (SaveResult)
    {
    case clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nSave succeeded\n";

        NewClient.Print();

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

int main()
{
    AddClient();
    return 0;
}