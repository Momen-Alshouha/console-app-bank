#pragma once
#include "clsScreen.h"

class clsUpdateUserScreen : public clsScreen {

public:
	static void UpdateUser() {
		string Username = clsInputValidate::ReadString("Enter Username : ");
		while (!clsUser::IsUserExist(Username))
		{
			cout << "User Not Found.\n";
			Username = clsInputValidate::ReadString("Enter Username :");
		}

		clsUser User = clsUser::Find(Username);
		system("cls");
		PrintUserCard(User);
		cout << "Update User info : \n";
		ReadUserInfo(User);
		clsUser::enSaveResults SaveResult;
		SaveResult = User.Save();
		system("cls");
		switch (SaveResult)
		{
		case clsUser::svSucceeded:
			cout << "\nAccount Updated Successfully!\n";
			PrintUserCard(User);
			break;
		case clsUser::svFaildUserExists:
			cout << "Error! Not Saved!\n";
			break;
		default:
			break;
		}
	}
};