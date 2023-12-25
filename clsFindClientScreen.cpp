#include "clsFindClientScreen.h"

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
