#include "clsAddClientScreen.h"

void clsAddClientScreen::AddClient()
{
	
	string AddMore = "";
	do
	{
		system("cls");
		clsScreen::_DrawScreenHeader("Add New Client");
		string AccountNumber = clsInputValidate::ReadString("Enter Account Number : ");
		bool IsClientExisit = clsClient::IsClientExisits(AccountNumber);
		while (IsClientExisit)
		{
			cout << "Account Number Is Already Taken! Enter Another one.\n";
			AccountNumber = clsInputValidate::ReadString("Enter Account Number : ");
			IsClientExisit = clsClient::IsClientExisits(AccountNumber);
		}

		clsClient NewClient = clsClient::GetAddNewClientObject(AccountNumber);
		ReadClientInfo(NewClient);
		clsClient::enSaveResult SaveResult = NewClient.Save();
		system("cls");
		switch (SaveResult)
		{
		case clsClient::svSuccess:
			cout << "Client Added Successfully.\n";
			 clsScreen::PrintClient(NewClient);
			cout << "\nDo You Want To Add More (yes,no) ? \n";
			cin >> AddMore;
			break;
		case clsClient::svFailed:
			cout << "\nError Save!\n";
			break;
		default:
			break;
		}
	} while (tolower(AddMore[0])=='y');
}
