#pragma once
#include "clsScreen.h"

class clsFindUserScreen : public clsScreen {

public:
	static void FindUser() {
		string Username = clsInputValidate::ReadString("Enter Username To Find : ");
		bool isUserExist = clsUser::IsUserExist(Username);
		if (isUserExist)
		{
			clsUser User = clsUser::Find(Username);
			PrintUserCard(User);
		}
		else {
			cout << "\nUser does not exisit!\nThank You!\n";
		}
	}
};