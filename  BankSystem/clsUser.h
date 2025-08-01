#pragma once

#include <iostream>
#include "clsString.h"
#include <string>
#include "clsPerson.h"
#include <vector>
#include <fstream>

using namespace std;

class clsUser : public clsPerson
{
private:

    enum enMode {eEmptyMode = 0, eUpdateMode = 1, eAddNewMode = 2};

    enMode _Mode;
    string _UserName;
    string _Password;
    short _Permissions;
    bool _MarkForDelete = false;

    static clsUser _ConvertLineToObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsUser(enMode::eUpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

    }

    static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
    {

        string sUser = "";
        sUser += User.FirstName() + Seperator;
        sUser += User.LastName() + Seperator;
        sUser += User.Email() + Seperator;
        sUser += User.Phone() + Seperator;
        sUser += User.UserName() + Seperator;
        sUser += User.Password() + Seperator;
        sUser += to_string(User.Permissions());

        return sUser;

    }

    static  vector <clsUser> _LoadUsersDataFromFile()
    {

        vector <clsUser> vUser;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLineToObject(Line);

                vUser.push_back(User);
            }

            MyFile.close();

        }

        return vUser;

    }

    static void _SaveUsersDataToFile(vector <clsUser> vUser)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser &C : vUser)
            {
               if (C._MarkForDelete == false)
               {
                    DataLine = _ConverUserObjectToLine(C);
                    MyFile << DataLine << endl;
               }
            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsUser> vUser;
        vUser = _LoadUsersDataFromFile();

        for (clsUser& U : vUser)
        {
            if (U.UserName() == UserName())
            {
                U = *this;
                break;
            }

        }

        _SaveUsersDataToFile(vUser);

    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConverUserObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::eEmptyMode, "", "", "", "", "", "", 0);
    }


public:

    clsUser (enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, short Permissions)
        : clsPerson (FirstName, LastName, Email, Phone)
    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }; 

    bool IsEmpty()
    {
        return (_Mode == enMode::eEmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkForDelete;
    }

    string UserName()
    {
        return _UserName;
    }

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string Password()
    {
        return _Password;
    }

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    short Permissions()
    {
        return _Permissions;
    }

    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToObject(Line);
                if (User.UserName() == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();

        }

        return _GetEmptyUserObject();
    }

    static clsUser Find(string UserName, string Password)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToObject(Line);
                if (User.UserName() == UserName && User.Password() == Password)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::eEmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }

        case enMode::eUpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::eAddNewMode:
        {
            //This will add new record to file or database
            if (clsUser::IsUserExist(_UserName))
            {
                return enSaveResults::svFaildUserExists;
            }
            else
            {
                _AddNew();
                //We need to set the mode to update after add new
                _Mode = enMode::eUpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }

    }

    static bool IsUserExist(string UserName)
    {

        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    bool Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName() == _UserName)
            {
                U._MarkForDelete = true;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;

    }

    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::eAddNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }
};
