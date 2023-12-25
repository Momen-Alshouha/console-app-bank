#include "clsDeleteScreen.h"

void clsDeleteScreen::DeleteClient()
{
	string DeleteMore = "";
	string AreYouSure;
	do
	{
		system("cls");
		clsScreen::_DrawScreenHeader("Delete Client");
		string AccountNumber = clsInputValidate::ReadString("Enter Account Number : ");
		while (!clsClient::IsClientExisits(AccountNumber))
		{
			cout << "Client Does Not Exist.\n";
			AccountNumber = clsInputValidate::ReadString("Enter Account Number : ");
		}

		clsClient Client = clsClient::Find(AccountNumber);
		clsScreen::PrintClient(Client);
		cout << "Are You Sure Do You Want To Delete This Client (yes , no) ? ";
		cin >> AreYouSure;
		if (tolower(AreYouSure[0]) == 'y')
		{
			if (Client.Delete())
			{
				cout << "Client Deleted Successfully\n";
				cout << "Do Yo Want To Delete More (yes , no) ? ";
				cin >> DeleteMore;
			}
		}
		else {
			cout << "\nThank You!\n";
		}
	} while (tolower(DeleteMore[0])=='y');
}

void clsDeleteScreen::DeleteAllClients()
{
	clsScreen::_DrawScreenHeader("Delete All Clients");
	string AreYouSure = "";
	cout << "Are You Sure Do You Want To Delete All Clients ? ";
	cin >> AreYouSure;
	if (tolower(AreYouSure[0]) == 'y')
	{
		if (clsClient::DeleteAll())
		{
			cout << "\nAll Clietnts Deleted Successfully!\n";
		}
		else {
			cout << "\nNo clients Exisits , Thank You!\n";
		}
	}
}
