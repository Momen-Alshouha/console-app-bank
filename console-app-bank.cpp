
#include <iostream>
#include "clsDate.h"
#include "clsInputValidation.h"
#include "clsPeriod.h"
#include "clsString.h"
#include "clsUtil.h"
#include "clsClient.h"

void ReadClientInfo(clsClient &Client) {
	Client.firstname = clsInputValidate::ReadString("Enter First Name : ");
	Client.lastname= clsInputValidate::ReadString("Enter Last Name : ");
	Client.email = clsInputValidate::ReadString("Enter Email : ");
	Client.pin_code= clsInputValidate::ReadString("Enter Pin Code : ");
	cout << "Enter Balance : ";
	Client.balance = clsInputValidate::ReadFloatNumber();
}

void UpdateClient() {
	string AccountNumber = clsInputValidate::ReadString("Enter Account Number : ");
	
	while (!clsClient::IsClientExisits(AccountNumber))
	{
		cout << "Client Not Found.\n";
		AccountNumber = clsInputValidate::ReadString("Enter Account Number : ");
	}

	clsClient Client = clsClient::Find(AccountNumber);
	system("cls");
	Client.Print();
	cout << "Update Client info : \n";
	ReadClientInfo(Client);
	clsClient::enSaveResult SaveResult;
	SaveResult = Client.Save();
	switch (SaveResult)
	{
	case clsClient::svSuccess:
		cout << "\nAccount Updated Successfully!\n";
		Client.Print();
		break;
	case clsClient::svFailed:
		cout << "Error! Not Saved!\n";
		break;
	default:
		break;
	}
}

using namespace std;

int main()
{


}
