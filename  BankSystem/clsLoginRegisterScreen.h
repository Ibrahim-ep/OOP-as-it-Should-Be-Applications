#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>

using namespace std;

class clsLoginRegisterScreen : protected clsScreen
{
    private:
    static void _PrintUserRegisterRecordLine(clsUser::stLoginRegisterRecord User)
    {
        cout << setw(8) << left << "" << "| " << setw(35) << left << User.Date;
        cout << "| " << setw(20) << left << User.UserName;
        cout << "| " << setw(20) << left << User.Password;
        cout << "| " << setw(10) << left << User.Permissions;

    }

public:

    static void ShowRegisterList()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
        {
            return;
        }


        vector <clsUser::stLoginRegisterRecord> vUsers = clsUser::GetRegisterList();

        string Title = "\t  Login Register List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Registers Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord &User : vUsers)
            {

                _PrintUserRegisterRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }
};