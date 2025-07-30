#include <string>
#include<iostream>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std; 

class clsBankClient : public clsPerson
{
private:

    enum enMode {eEmptyMode = 1,eUpdateMode =2 };

    enMode _Mode;
    string _AccountNumber;
    string _Pincode;
    float _AccountBalance;

    static clsBankClient _ConvertLineToClientObject(string Line,string Seperator = "#//#")
    {
        vector <string> vClientData = clsString::Split(Line,Seperator);

        return clsBankClient(enMode::eUpdateMode,vClientData[0],vClientData[1],vClientData[2],vClientData[3],vClientData[4],
        vClientData[5],stod(vClientData[6]));
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::eEmptyMode, "", "", "", "", "", "",0);
    }

public:

    clsBankClient(enMode Mode,string FirstName,string LastName,string Email,string Phone,string AccountNumber,string Pincode,float AccountBalance) :
        clsPerson(FirstName,LastName,Email,Phone)
    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _AccountBalance = AccountBalance;
        _Pincode = Pincode;
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::eEmptyMode);
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void setPincode(string Pincode)
    {
        _Pincode = Pincode;
    }

    string Pincode()
    {
        return _Pincode;
    }

    void setAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float AccountBalance()
    {
        return _AccountBalance;
    }

    void Print()
    {
        cout << "\nClient Card :\n";
        cout << "_______________________\n";
        cout << "First Name     : " << GetFirstName();
        cout << "\nLast Name      : " << GetLastName();
        cout << "\nFull Name      : " << FullName();
        cout << "\nAccount Number : " << AccountNumber();
        cout << "\nPIN code       : " << Pincode();
        cout << "\nAccountBalance : " << AccountBalance();
        cout << "\n_______________________\n";
    }

    static clsBankClient Find(string AccountNumber)
    {
        fstream MyFile;

        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile,Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);

                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                } 
            }
            
        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber,string Pincode)
    {
        fstream MyFile;

        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile,Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);

                if (Client.AccountNumber() == AccountNumber && Client.Pincode() == Pincode)
                {
                    MyFile.close();
                    return Client;
                } 
            }
            
        }

        return _GetEmptyClientObject();
    }
    
    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        return (!Client1.IsEmpty());
    }
};