#include "clsLoginScreen.h"

void clsLoginScreen::_Login()
{
    bool LoginFaild = false;

    string Username, Password;
    do
    {

        if (LoginFaild)
        {
            system("cls");
            _DrawScreenHeader(" Login Screen");
            cout << "\nInvlaid Username/Password!\n\n";
        }

        cout << "Enter Username? ";
        cin >> Username;

        cout << "Enter Password? ";
        cin >> Password;

        CurrentUser = clsUser::Find(Username, Password);

        LoginFaild = CurrentUser.IsEmpty();

    } while (LoginFaild);

    clsMainMenu::ShowMainMenu();
}

void clsLoginScreen::ShowLoginScreen()
{
    system("cls");
    _DrawScreenHeader(" Login Screen");
    _Login();

}
