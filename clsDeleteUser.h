#pragma once
#include "clsScreen.h"

class clsDeleteUser : public clsScreen {


	static void _MarkUserForDelete(clsUser &User) {
		User.markForDeletion = true;
	}

public:
	static void DeleteUser() {
		string AreYouSure = "y";
		string Username = clsInputValidate::ReadString("Enter Username : ");
		bool IsUserExist = clsUser::IsUserExist(Username);
		if (!IsUserExist)
		{
			cout << "\nUser is not exisit!\n";
		}
		else {
			clsUser UserToDelete = clsUser::Find(Username);
			PrintUser(UserToDelete);
			cout << "\nAre You Sure Do You Want To Delete This User (y,n) ? ";
			cin >> AreYouSure;
			if (tolower(AreYouSure[0]) == 'y')
			{
				_MarkUserForDelete(UserToDelete);
				if (UserToDelete.Delete())
				{
					cout << "\nUser Deleted Successfully!\nThank You!\n";
				}
				else {
					cout << "User NOT Deleted!\Somthing wrong happened!";
				}
			}
		}
	}
};