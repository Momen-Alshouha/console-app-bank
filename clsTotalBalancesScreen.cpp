#include "clsTotalBalancesScreen.h"

void clsTotalBalancesScreen::PrintClientRecordBalanceLine(clsClient Client)
{
	cout << "| " << setw(15) << left << Client.account_number;
	cout << "| " << setw(40) << left << Client.fullname;
	cout << "| " << setw(12) << left << Client.balance;
}

void clsTotalBalancesScreen::ShowTotalBalances()
{
	clsScreen::_DrawScreenHeader("Total Balances!");
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
