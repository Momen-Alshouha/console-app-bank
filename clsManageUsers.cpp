#include "clsManageUsers.h"

void clsManageUsers::_PerformManageUsersMenuOption(enManageUsersMenuOption Option)
{
    system("cls");
    switch (Option)
    {
    case clsManageUsers::eListUsers:
        _ListUsers();
        _GoBackToManageUsersMenu();
        break;
    case clsManageUsers::eAddUser:
        _AddUser();
        _GoBackToManageUsersMenu();
        break;
    case clsManageUsers::eDeleteUser:
        _DeleteUser();
        _GoBackToManageUsersMenu();
    case clsManageUsers::eUpdateUser:
        _UpdateUser();
        _GoBackToManageUsersMenu();
        break;
        break;
    case clsManageUsers::eFindUser:
        _FindUser();
        _GoBackToManageUsersMenu();
        break;
    case clsManageUsers::eMainMenu:
        _MainMenu();
        break;
    default:
        break;
    }
}

void clsManageUsers::_ListUsers()
{
    _DrawScreenHeader("List Users");
    clsListUsersScreen::ListUsers();
}

void clsManageUsers::_AddUser()
{
    _DrawScreenHeader("Add User");
    clsAddNewUserScreen::ShowAddNewUserScreen();
}

void clsManageUsers::_UpdateUser()
{
    _DrawScreenHeader("Update User");
    clsUpdateUserScreen::UpdateUser();
}

void clsManageUsers::_DeleteUser()
{
    _DrawScreenHeader("Delete User");
    clsDeleteUser::DeleteUser();
}

void clsManageUsers::_FindUser()
{
    _DrawScreenHeader("Find User");
    
    clsFindUserScreen::FindUser();

}

void clsManageUsers::_GoBackToManageUsersMenu()
{

    cout << "\nPress any key to go back to manage users menu\n";
    system("pause>0");
    ShowManageUsersScreen();
}

void clsManageUsers::_MainMenu()
{
    clsMainMenu::ShowMainMenu();
}

void clsManageUsers::ShowManageUsersScreen()
{
    system("cls");
    _DrawScreenHeader("Manage Users Screen");
    cout << "\t[1] List Users.\n";
    cout << "\t[2] Add New User.\n";
    cout << "\t[3] Delete User.\n";
    cout << "\t[4] Update User.\n";
    cout << "\t[5] Find User.\n";
    cout << "\t[6] Main Menu.\n";
    cout << "====================================\n";
    cout << "Enter option [1-6] : ";
    _PerformManageUsersMenuOption((enManageUsersMenuOption)clsInputValidate::ReadIntNumberBetween(1, 6));
}
