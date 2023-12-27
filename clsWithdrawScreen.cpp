#include "clsWithdrawScreen.h"

void clsWithdrawScreen::ShowWithdrawScreen()
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
		cout << "\n\nNOTE : you current balance is : " << Client.balance <<endl<< endl;
		cout << "Enter Amount To Withdraw : ";
		float amount = clsInputValidate::ReadDblNumberBetween(1, Client.balance);
		Client.Withdraw(amount);
		cout << "Your New Balance Is : " << Client.balance << endl;
	}
}
