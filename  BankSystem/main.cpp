#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsUtil.h"

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

void DeleteClient()
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

    cout << "\nAre you sure you want to delete this client y/n? ";
    
    char Answer = 'n';
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {
       

        if (Client1.Delete())
        {
            cout << "\nClient Deleted Successfully :-)\n";

            Client1.Print();
        }
        else
        {
            cout << "\nError Client Was not Deleted\n";
        }
    }
}

void PrintClientRecordLine(clsBankClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber();
    cout << "| " << setw(20) << left << Client.FullName();
    cout << "| " << setw(12) << left << Client.Phone();
    cout << "| " << setw(20) << left << Client.Email();
    cout << "| " << setw(10) << left << Client.PinCode();
    cout << "| " << setw(12) << left << Client.AccountBalance();
}

void ShowClientsList()
{
    vector <clsBankClient> vClient = clsBankClient::GetClientsList();

    cout << "\n\t\t\t\t\tClient List (" << vClient.size() <<") Clients\n";
    cout << "\n--------------------------------------------------------------";
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

    ShowBalancesList();

    return 0;
}