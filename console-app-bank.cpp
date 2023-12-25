
#include <iostream>
#include "clsDate.h"
#include "clsInputValidation.h"
#include "clsPeriod.h"
#include "clsString.h"
#include "clsUtil.h"
#include "clsClient.h"
#include "clsMainMenu.h"
#include <iomanip>
#include "clsScreen.h"

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


void PrintClientRecordBalanceLine(clsClient Client)
{

	cout << "| " << setw(15) << left << Client.account_number;
	cout << "| " << setw(40) << left << Client.fullname;
	cout << "| " << setw(12) << left << Client.balance;

}


void ShowTotalBalances()
{

	vector <clsClient> vClients = clsClient::GetClientsList();

	cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	double TotalBalances = clsClient::GetTotalBalances();

	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";
	else

		for (clsClient& Client : vClients)
		{
			PrintClientRecordBalanceLine(Client);
			cout << endl;
		}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
	cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")\n\n";
}

int main()
{
	clsMainMenu::ShowMainMenu();
	
}
