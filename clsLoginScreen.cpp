#include "clsLoginScreen.h"

string clsLoginScreen::_GenerateLoginLogLine(clsUser& User) {
    string LogLine = "";
    clsDate Date;
    string DateAndTime = clsDate::GetTodayAndTime() + "#//#";
    LogLine += DateAndTime;
    LogLine += User.UserName + "#//#";
    LogLine += User.fullname;
    return LogLine;
}

void clsLoginScreen::_AddUserLoginToLogFile(clsUser& User)
{
    string LogLine = _GenerateLoginLogLine(User);
    fstream LogsFile;
    LogsFile.open(LogFilePath, ios::app);
    if (LogsFile.is_open())
    {
        LogsFile << LogLine << endl; 
        LogsFile.close();
    }
}

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
        _AddUserLoginToLogFile(UserSession::getCurrentUser());
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
