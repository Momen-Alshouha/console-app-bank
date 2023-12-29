#pragma once
#include "clsScreen.h"
#include "clsUser.h"

class clsListUsersScreen : public clsScreen
{
private:
	

public:

	static void ListUsers() {
		vector<clsUser> vUsers = clsUser::GetUsersList();

		cout << "\n\t\t\t\t\tUsers List (" << vUsers.size() << ") Client(s).";
		cout << "\n_______________________________________________________";
		cout << "_____________________________________________________\n" << endl;

		cout << "| " << left << setw(22) << "Full Name";
		cout << "| " << left << setw(20) << "Phone";
		cout << "| " << left << setw(17) << "Email";
		cout << "| " << left << setw(12) << "Username";
		cout << "| " << left << setw(12) << "Password";
		cout << "| " << left << setw(12) << "Permissions";
		cout << "\n_______________________________________________________";
		cout << "_____________________________________________________\n" << endl;

		if (vUsers.size() == 0)
			cout << "\t\t\t\tNo Users Available In the System!";
		else

			for (clsUser& User : vUsers)
			{
				PrintUserRecord(User);
				cout << endl;
			}

		cout << "\n_______________________________________________________";
		cout << "_____________________________________________________\n" << endl;
	};

};
