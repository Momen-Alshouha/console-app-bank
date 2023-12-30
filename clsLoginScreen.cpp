#include "clsLoginScreen.h"

void clsLoginScreen::_Login()
{
    bool LoginFailed = false;
    short LoginAttemps = 3;
    string Username, Password;
    do
    {

        if (LoginFailed)
        {
            LoginAttemps--;
            system("cls");
            _DrawScreenHeader(" Login Screen");
            cout << "Invlaid Username/Password!\nYou have " << LoginAttemps << " Trials To login\n";
        }

        cout << "Enter Username? ";
        cin >> Username;

        cout << "Enter Password? ";
        Password = clsInputValidate::ReadPassword();

        UserSession::setCurrentUser(Username, Password);

        LoginFailed = UserSession::getCurrentUser().IsEmpty();

    } while (LoginFailed && LoginAttemps>1);

    if (!LoginFailed)
    {
        clsMainMenu::ShowMainMenu();
    }
    else {
        system("cls");
        _DrawScreenHeader("You Are Blocked, Please Try To Login Later!\n");
    }
}

void clsLoginScreen::ShowLoginScreen()
{
    system("cls");
    _DrawScreenHeader(" Login Screen");
    _Login();

}
