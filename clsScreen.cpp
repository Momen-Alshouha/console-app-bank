#include "clsScreen.h"


void clsScreen::PrintSystemDate(clsDate Date)
{
    Date.Print();
}

void clsScreen::ReadClientInfo(clsClient& Client)
{
	Client.firstname = clsInputValidate::ReadString("Enter First Name : ");
	Client.lastname = clsInputValidate::ReadString("Enter Last Name : ");
	Client.email = clsInputValidate::ReadString("Enter Email : ");
	Client.phone = clsInputValidate::ReadString("Enter Phone : ");
	Client.pin_code = clsInputValidate::ReadString("Enter Pin Code : ");
	cout << "Enter Balance : ";
	Client.balance = clsInputValidate::ReadFloatNumber();
}

void clsScreen::PrintClient(clsClient& client)
{

	cout << "\nClient Card:";
	cout << "\n___________________";
	cout << "\nFirstName   : " << client.firstname;
	cout << "\nLastName    : " << client.lastname;
	cout << "\nFull Name   : " << client.fullname;
	cout << "\nEmail       : " << client.email;
	cout << "\nPhone       : " << client.phone;
	cout << "\nAcc. Number : " << client.account_number;
	cout << "\nPassword    : " << client.pin_code;
	cout << "\nBalance     : " << client.balance;
	cout << "\n___________________\n";
}

void clsScreen::_DrawScreenHeader(string Title, string SubTitle)
{
    clsDate Date;
    cout << "=================================================";
    cout << "\n\t  " << Title<<"     Date : "; 
    clsScreen::PrintSystemDate(Date);
    if (SubTitle != "")
    {
        cout << "\n\t" << SubTitle;
    }
    cout << "\n=================================================\n";
}

