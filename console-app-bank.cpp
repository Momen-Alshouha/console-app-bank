
#include <iostream>
#include "clsDate.h"
#include "clsInputValidation.h"
#include "clsPeriod.h"
#include "clsString.h"
#include "clsUtil.h"
#include "clsClient.h"


using namespace std;


void ReadClientInfo(clsClient &Client) {
	Client.firstname = clsInputValidate::ReadString("Enter First Name : ");
	Client.lastname= clsInputValidate::ReadString("Enter Last Name : ");
	Client.email = clsInputValidate::ReadString("Enter Email : ");	
	Client.phone = clsInputValidate::ReadString("Enter Phone : ");
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

void AddClient() {
	cout << "Add New Client : \n";
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
		NewClient.Print();
		break;
	case clsClient::svFailed:
		cout << "\nError Save!\n";
		break;
	default:
		break;
	}
}

void DeleteClient() {
	string AreYouSure;
	string AccountNumber = clsInputValidate::ReadString("Enter Account Number : ");
	while (!clsClient::IsClientExisits(AccountNumber))
	{
		cout << "Client Does Not Exist.\n";
		AccountNumber = clsInputValidate::ReadString("Enter Account Number : ");
	}

	clsClient Client = clsClient::Find(AccountNumber);
	Client.Print();
	cout << "Are You Sure Do You Want To Delete This Client ? ";
	cin >> AreYouSure;
	if (tolower(AreYouSure[0])=='y')
	{
		if (Client.Delete())
		{
			cout << "Client Deleted Successfully\n";
		}
	}
	else {
		cout << "\nThank You!\n";
	}
}

int main()
{
	DeleteClient();
}
