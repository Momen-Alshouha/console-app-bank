#include "clsDepositeScreen.h"
#include "clsClient.h"


void clsDepositeScreen::ShowDepositeScreen()
{
	_DrawScreenHeader("Deposite Screen");
	string AccountNumber = clsInputValidate::ReadString("Enter Account Number : ");
	bool isExist = clsClient::IsClientExisits(AccountNumber);
	if (!isExist)
	{
		cout << "Client is not exisit!\n";
	}
	else {
		clsClient Client = clsClient::Find(AccountNumber);
		PrintClient(Client);
		cout << "Enter Amount To Deposite : ";
		float amount = clsInputValidate::ReadDblNumber();
		Client.Deposite(amount);
		cout << "Your New Balance Is : " << Client.balance << endl;
	}
}
