#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include <iomanip>
#include "clsClientsListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "Global.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:

    enum enMainMenueOptions {
            eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
            eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
            eManageUsers = 7, eLoginRegister = 8, eExit = 9
        };

       static short _ReadMainMenueOption()
        {
            cout <<setw(37) << left << ""<< "Choose what do you want to do? [1 to 9]? ";
            short Choice = clsInputValidate::ReadShortNumberBetween(1,9,"Enter Number between 1 to 9? ");
            return Choice;
        }

       static  void _GoBackToMainMenue()
        {   
            ShowMainMenue();
        }
       
       static void _ShowAllClientsScreen()
       {
            clsClientsListScreen::ShowClientsList();
       }

       static void _ShowAddNewClientsScreen()
       {
            clsAddNewClientScreen::AddClient();     
       }

       static void _ShowDeleteClientScreen()
       {
           clsDeleteClientScreen::DeleteClient();

       }

       static void _ShowUpdateClientScreen()
       {
           clsUpdateCleintScreen::UpdateClientScreen();
       }

       static void _ShowFindClientScreen()
       {
           clsFindClientScreen::ShowFindClientScreen();
       }

       static void _ShowTransactionsMenue()
       {
            clsTransactionScreen::ShowTransactionsMenue();
       }

       static void _ShowManageUsersMenue()
       {
           clsManageUsersScreen::ShowManageUsersMenue();
       }

       static void _ShowLoginRegisterScreen()
       {
            clsLoginRegisterScreen::ShowRegisterList();
       }

       static void _Logout()
        {
            CurrentUser = clsUser::Find("","");
        }

       static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
        {
            switch (MainMenueOption)
            {
            case enMainMenueOptions::eListClients:
            {
                _ShowAllClientsScreen();
                _GoBackToMainMenue();
                break;
            }
            case enMainMenueOptions::eAddNewClient:
               _ShowAddNewClientsScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eDeleteClient:
                _ShowDeleteClientScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eUpdateClient:
                _ShowUpdateClientScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eFindClient:
                _ShowFindClientScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eShowTransactionsMenue:
                _ShowTransactionsMenue();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eManageUsers:
                _ShowManageUsersMenue();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eLoginRegister:
                _ShowLoginRegisterScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eExit:
                _Logout();
                break;
            }

        }



	public:
       

       static void ShowMainMenue()
        {
        
            _DrawScreenHeader("\t\tMain Screen");

            cout << setw(37) << left <<""<< "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
            cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
            cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
            cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
            cout << setw(37) << left << "" << "\t[5] Find Client.\n";
            cout << setw(37) << left << "" << "\t[6] Transactions.\n";
            cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
            cout << setw(37) << left << "" << "\t[8] Login Register.\n";
            cout << setw(37) << left << "" << "\t[9] Logout.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
        }
};