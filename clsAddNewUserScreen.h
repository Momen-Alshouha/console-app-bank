#pragma once
#include "clsScreen.h"

class clsAddNewUserScreen : public clsScreen {


public:

    static void ShowAddNewUserScreen()
    {
        string UserName = "";
        UserName = clsInputValidate::ReadString("\nEnter User Name : ");

        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName Is Already Used , ";
            UserName = clsInputValidate::ReadString("Choose another one : ");
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nUser Addeded Successfully :-)\n";
           PrintUser(NewUser);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError User was not saved because it's Empty";
            break;

        }
        case clsUser::enSaveResults::svFaildUserExists:
        {
            cout << "\nError User was not saved because UserName is used!\n";
            break;

        }
        }
    }
};