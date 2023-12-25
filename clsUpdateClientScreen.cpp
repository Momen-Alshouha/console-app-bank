#include "clsUpdateClientScreen.h"

void clsUpdateClientScreen::UpdateClient()
{

	clsScreen::_DrawScreenHeader("Update Client Screen");
	string AccountNumber = clsInputValidate::ReadString("Enter Account Number : ");
	while (!clsClient::IsClientExisits(AccountNumber))
	{
		cout << "Client Not Found.\n";
		AccountNumber = clsInputValidate::ReadString("Enter Account Number : ");
	}

	clsClient Client = clsClient::Find(AccountNumber);
	system("cls");
	clsScreen::PrintClient(Client);
	cout << "Update Client info : \n";
	ReadClientInfo(Client);
	clsClient::enSaveResult SaveResult;
	SaveResult = Client.Save();
	switch (SaveResult)
	{
	case clsClient::svSuccess:
		cout << "\nAccount Updated Successfully!\n";
		clsScreen::PrintClient(Client);
		break;
	case clsClient::svFailed:
		cout << "Error! Not Saved!\n";
		break;
	default:
		break;
	}

}
