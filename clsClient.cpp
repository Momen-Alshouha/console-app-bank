#include "clsClient.h"
#include <vector>
#include <string>
#include <fstream>
#include "clsString.h"

const string clsClient::ClientFileName = "Clients.txt";

string clsClient::_ConvertClientObjectToLine(clsClient Client,string Line, string Delimeter)
{
	string ClientLine = "";
	ClientLine += Client.firstname+ Delimeter;
	ClientLine += Client.lastname + Delimeter;
	ClientLine += Client.email+ Delimeter;
	ClientLine += Client.phone+ Delimeter;
	ClientLine += Client.account_number+ Delimeter;
	ClientLine += Client.pin_code + Delimeter;
	ClientLine += to_string(Client.balance);
	return ClientLine;
}

clsClient clsClient::_ConvertClientLineToClientObject(string Line,string Delimeter)
{
	vector<string> vData = clsString::Split(Line, Delimeter);
	return clsClient(UpdateMode, vData[0], vData[1], vData[2], vData[3], vData[4], vData[5], stof(vData[6]));
}

clsClient clsClient::_GetEmptyClientObject()
{
	return clsClient(EmptyMode, "", "", "", "", "", "", 0);
}

clsClient::clsClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float Balance)
	:clsPerson(FirstName, LastName, Email, Phone), _AccountNumber(AccountNumber), _PinCode(PinCode), _Balance(Balance),_Mode(Mode) {}


string clsClient::GetAccountNumber()
{
	return _AccountNumber;
};

float clsClient::GetBalance() {
	return _Balance;
}

void clsClient::SetBalance(float Balance) {
	_Balance = Balance;
}

void clsClient::SetPinCode(string PinCode) {
	_PinCode = PinCode;
}

string clsClient::GetPinCode() {
	return _PinCode;
}

clsClient clsClient::Find(string AccountNumber) {
	fstream ClientsFile;
	string ClientLine = "";
	ClientsFile.open(ClientFileName, ios::in);
	if (ClientsFile.is_open())
	{
		while (getline(ClientsFile,ClientLine))
		{
			clsClient Client = _ConvertClientLineToClientObject(ClientLine);
			if (Client.account_number==AccountNumber)
			{
				ClientsFile.close();
				return Client;
			}
		}
	}
	return _GetEmptyClientObject();
};


clsClient clsClient::Find(string AccountNumber,string PinCode) {

	clsClient Client = Find(AccountNumber);
	
	if (Client.pin_code == PinCode && !Client.IsEmplty()) {
		return Client;
	} 

	return _GetEmptyClientObject();
}

bool clsClient::IsEmplty()
{
	return (_Mode == EmptyMode);
}

bool clsClient::IsClientExisits(string AccountNumber)
{
	clsClient Client =clsClient::Find(AccountNumber);
	return !Client.IsEmplty();
	
}

void clsClient::Print()
{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << firstname;
		cout << "\nLastName    : " << lastname;
		cout << "\nFull Name   : " << fullname;
		cout << "\nEmail       : " << email;
		cout << "\nPhone       : " << phone;
		cout << "\nAcc. Number : " << account_number;
		cout << "\nPassword    : " << pin_code;
		cout << "\nBalance     : " << balance;
		cout << "\n___________________\n";
}
;
