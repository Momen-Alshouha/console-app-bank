
#include <iostream>
#include "clsDate.h"
#include "clsInputValidation.h"
#include "clsPeriod.h"
#include "clsString.h"
#include "clsUtil.h"
#include "clsClient.h"
#include <iomanip>
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

void PrintClientRecordLine(clsClient Client)
{

	cout << "| " << setw(15) << left << Client.account_number;
	cout << "| " << setw(20) << left << Client.fullname;
	cout << "| " << setw(12) << left << Client.phone;
	cout << "| " << setw(20) << left << Client.email;
	cout << "| " << setw(10) << left << Client.pin_code;
	cout << "| " << setw(12) << left << Client.account_number;

}

void ShowClientsList()
{
	vector <clsClient> vClients = clsClient::GetClientsList();

	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(20) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(20) << "Email";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";
	else

		for (clsClient &Client : vClients)
		{

			PrintClientRecordLine(Client);
			cout << endl;
		}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

}

int main()
{
	ShowClientsList();
}
