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

using namespace std;

class clsMainScreen : protected clsScreen
{
private:

    enum enMainMenueOptions {
            eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
            eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
            eManageUsers = 7, eExit = 8
        };

       static short _ReadMainMenueOption()
        {
            cout <<setw(37) << left << ""<< "Choose what do you want to do? [1 to 8]? ";
            short Choice = clsInputValidate::ReadShortNumberBetween(1,8,"Enter Number between 1 to 8? ");
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
           cout << "\nTransactions Menue Will be here...\n";

       }

       static void _ShowManageUsersMenue()
       {
           cout << "\nUsers Menue Will be here...\n";

       }

       static void _ShowEndScreen()
           {
               cout << "\nEnd Screen Will be here...\n";

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
                break;

            case enMainMenueOptions::eManageUsers:
                _ShowManageUsersMenue();
                break;

            case enMainMenueOptions::eExit:
                _ShowEndScreen();
                //Login();

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
            cout << setw(37) << left << "" << "\t[8] Logout.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
        }
};