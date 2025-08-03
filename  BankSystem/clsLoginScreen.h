#pragma once

#include <iostream>
#include "clsMainScreen.h"
#include "Global.h"
#include "clsScreen.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{
private:

    static bool _Login()
    {
        bool LoginFailed = false;

        string UserName = " ", Password = " ";

        static short FailTimesCounter = 0;

        do
        {
            if (LoginFailed)
            {
                cout << "\nInvalid Username/Password\n";
                FailTimesCounter++;

                if (FailTimesCounter == 3)
                {
                    _DrawScreenHeader("\t   System Locked");
                    return false;
                }
            }

            cout << "\nPleas enter UserName : ";
            cin >> UserName;

            cout << "\n\nPleas enter Password : ";
            cin >> Password;

            CurrentUser = clsUser::Find(UserName,Password);

            LoginFailed = CurrentUser.IsEmpty();

        } while (LoginFailed);
        

        CurrentUser.RegisterLogin();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:

    static bool ShowLoginScreen()
    {
        _DrawScreenHeader("\t   Login Screen");
        _Login();
    }
};