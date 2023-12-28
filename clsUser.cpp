#include "clsUser.h"

const string clsUser::UsersFileName = "users.txt";

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

clsUser::enPermissions clsUser::GetPermission()
{
	return _Permissions;
}

void clsUser::SetPermission(int Permission)
{
	_Permissions = (enPermissions)Permission;	
}
