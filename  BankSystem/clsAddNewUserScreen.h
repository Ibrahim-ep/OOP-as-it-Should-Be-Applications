#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include <iomanip>

using namespace std;

class clsAddNewUserScreen : protected clsScreen
{
private:

    static short _ReadUserPermissions()
    {
        short Permissions = 0;
        char Answer = 'n';

        cout << "Do you want to give full access ? Y/N ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::eAll;
            return Permissions;
        }

        cout << "Do you want to give show client list access ? Y/N ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "Do you want to give Add new client access ? Y/N ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "Do you want to give delete client access ? Y/N ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "Do you want to give Update client access ? Y/N ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "Do you want to give Find client access ? Y/N ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "Do you want to give Transaction access ? Y/N ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "Do you want to give Manage Users access ? Y/N ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        return Permissions;
    }

    static void _ReadUserInfo(clsUser &User)
    {
        string Input = " ";

        cout << "\nEnter First Name : ";
        Input = clsInputValidate::ReadString();
        User.SetFirstName(Input);

        cout << "\nEnter Last Name : ";
        Input = clsInputValidate::ReadString();
        User.SetLastName(Input);

        cout << "\nEnter E-mail : ";
        Input = clsInputValidate::ReadString();
        User.SetEmail(Input);

        cout << "\nEnter Phone Number : ";
        Input = clsInputValidate::ReadString();
        User.SetPhone(Input);

        cout << "\nEnter Password Code : ";
        Input = clsInputValidate::ReadString();
        User.SetPassword(Input);

        cout << "\nEnter Permissions : \n\n";
        User.SetPermissions(_ReadUserPermissions());
       
    }

    static void _PrintUser(clsUser User)
    {
    
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName();
        cout << "\nLastName    : " << User.LastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email();
        cout << "\nPhone       : " << User.Phone();
        cout << "\nUser Number : " << User.UserName();
        cout << "\nPassword    : " << User.Password();
        cout << "\nPermissions : " << User.Permissions();
        cout << "\n___________________\n";

    }

public:

    static void AddUser()
    {
        string UserName = " ";

        _DrawScreenHeader("\t   Add New User Screen");

        cout << "Pleas enter username : ";
        UserName = clsInputValidate::ReadString();

        while (clsUser::IsUserExist(UserName))
        {
            cout << "User already exist, Plaes enter username number : ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUser(UserName);
    
        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nSave succeeded\n";

            _PrintUser(NewUser);

            break;
        }
        case clsUser::enSaveResults::svFaildUserExists:
        {
            cout << "\nSave Failed, User already exist\n";
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nSave Failed, Object was empty\n";
            break;
        }
        }
    }
};