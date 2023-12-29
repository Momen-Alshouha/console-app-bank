#include "clsUser.h"

const string clsUser::UsersFileName = "users.txt";

clsUser::clsUser(enMode Mode, string FirstName, string LastName,
    string Email, string Phone, string UserName, string Password,
    int Permissions) :
    clsPerson(FirstName, LastName, Email, Phone)

{
    _Mode = Mode;
    _Username = UserName;
    _Password = Password;
    _Permissions = Permissions;
}

string clsUser::GetUserName()
{
	return _Username;
}

void clsUser::SetUserName(string Username)
{
	_Username = Username;
}

string clsUser::GetPassword()
{
	return _Password;
}

void clsUser::SetPassword(string Password)
{
	_Password = Password;
}

int clsUser::GetPermissions() {
    return _Permissions;
}

void clsUser::SetPermission(int Permission)
{
	_Permissions = (enPermissions)Permission;	
}

clsUser clsUser::_ConvertLinetoUserObject(string Line, string Seperator)
{
    vector<string> vUserData;
    vUserData = clsString::Split(Line, Seperator);

    return clsUser(clsUser::enMode::enUpdateMode, vUserData[0], vUserData[1], vUserData[2],
        vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));
}

string clsUser::_ConverUserObjectToLine(clsUser User, string Seperator)
{

    string UserRecord = "";
    UserRecord += User.firstname+ Seperator;
    UserRecord += User.lastname + Seperator;
    UserRecord += User.email + Seperator;
    UserRecord += User.phone + Seperator;
    UserRecord += User.username+ Seperator;
    UserRecord += User.password + Seperator;
    UserRecord += to_string(User.permissions);

    return UserRecord;

}

vector<clsUser> clsUser::_LoadUsersDataFromFile()
{

    vector <clsUser> vUsers;

    fstream MyFile;
    MyFile.open("Users.txt", ios::in);

    if (MyFile.is_open())
    {

        string Line;


        while (getline(MyFile, Line))
        {

            clsUser User = _ConvertLinetoUserObject(Line);

            vUsers.push_back(User);
        }

        MyFile.close();

    }

    return vUsers;

}

void clsUser::_SaveUsersDataToFile(vector <clsUser> vUsers)
{
    fstream MyFile;
    MyFile.open("Users.txt", ios::out); 

    string DataLine;

    if (MyFile.is_open())
    {

        for (clsUser U : vUsers)
        {
            if (U.markForDeletion == false)
            {
                DataLine = _ConverUserObjectToLine(U);
                MyFile << DataLine << endl;

            }

        }

        MyFile.close();

    }

}