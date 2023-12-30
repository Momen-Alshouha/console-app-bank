#include "clsLoginScreen.h"

void clsLoginScreen::_Login()
{
    bool LoginFailed = false;

    string Username, Password;
    do
    {

        if (LoginFailed)
        {
            system("cls");
            _DrawScreenHeader(" Login Screen");
            cout << "\nInvlaid Username/Password!\n\n";
        }

        cout << "Enter Username? ";
        cin >> Username;

        cout << "Enter Password? ";
        cin >> Password;

        UserSession::setCurrentUser(Username, Password);

        LoginFailed = UserSession::getCurrentUser().IsEmpty();

    } while (LoginFailed);

    clsMainMenu::ShowMainMenu();
}

void clsLoginScreen::ShowLoginScreen()
{
    system("cls");
    _DrawScreenHeader(" Login Screen");
    _Login();

}
