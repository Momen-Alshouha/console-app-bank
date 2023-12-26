#include "clsFindClientScreen.h"

void clsFindClientScreen::PrintClientRecordBalanceLine(clsClient Client)
{
	cout << "| " << setw(15) << left << Client.account_number;
	cout << "| " << setw(40) << left << Client.fullname;
	cout << "| " << setw(12) << left << Client.balance;
}

void clsFindClientScreen::FindClientScreen()
{
	clsScreen::_DrawScreenHeader("Find Client Screen");
	string AccoundNumber = clsInputValidate::ReadString("Enter Account number : ");
	bool isExisit = clsClient::IsClientExisits(AccoundNumber);
	if (!isExisit)
	{
		cout << "\nClient Not Exisit!\n";
	}
	else {
		clsClient Client = clsClient::Find(AccoundNumber);
		clsScreen::PrintClient(Client);
	}
	
}
