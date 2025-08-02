#pragma once

#include <iostream>
#include "clsMainScreen.h"
#include "Global.h"
#include "clsScreen.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{
private:

    static void _Login()
    {
        bool LoginFailed = false;

        string UserName = " ", Password = " ";

        do
        {
            if (LoginFailed)
            {
                cout << "\nInvalid Username/Password\n";
            }

            cout << "\nPleas enter UserName : ";
            cin >> UserName;

            cout << "\n\nPleas enter Password : ";
            cin >> Password;

            CurrentUser = clsUser::Find(UserName,Password);

            LoginFailed = CurrentUser.IsEmpty();

        } while (LoginFailed);
        

        clsMainScreen::ShowMainMenue();
    }

public:

    static void ShowLoginScreen()
    {
        _DrawScreenHeader("\t   Login Screen");
        _Login();
    }
};