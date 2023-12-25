#include "clsClientListScreen.h"


void clsClientListScreen::PrintClientRecordLine(clsClient Client)
{
	cout << "| " << setw(15) << left << Client.account_number;
	cout << "| " << setw(20) << left << Client.fullname;
	cout << "| " << setw(12) << left << Client.phone;
	cout << "| " << setw(20) << left << Client.email;
	cout << "| " << setw(10) << left << Client.pin_code;
	cout << "| " << setw(12) << left << Client.account_number;
}


void clsClientListScreen::ShowClientsList()
{
	vector <clsClient> vClients = clsClient::GetClientsList();
	_DrawScreenHeader("Clients List");
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

		for (clsClient& Client : vClients)
		{
			PrintClientRecordLine(Client);
			cout << endl;
		}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

