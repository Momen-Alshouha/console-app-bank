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

void clsScreen::ReadUserInfo(clsUser& User) {
	User.firstname = clsInputValidate::ReadString("Enter First Name : ");
	User.lastname = clsInputValidate::ReadString("Enter Last Name : ");
	User.email = clsInputValidate::ReadString("Enter Email : ");
	User.phone = clsInputValidate::ReadString("Enter Phone Number : ");
	User.Password= clsInputValidate::ReadString("Enter Password : ");
	cout << "\nEnter Permission: ";
	User.Permissions= _ReadPermissionsToSet();
}

int clsScreen::_ReadPermissionsToSet() {
    
    int Permissions = 0;
    char Answer = 'n';

    cout << "\nDo you want to give full access? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        return -1;
    }

    cout << "\nDo you want to give access to : \n ";

    cout << "\nShow Client List? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {


        Permissions += clsUser::enPermissions::pListClients;
    }

    cout << "\nAdd New Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += clsUser::enPermissions::pAddNewClient;
    }

    cout << "\nDelete Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += clsUser::enPermissions::pDeleteClient;
    }

    cout << "\nUpdate Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += clsUser::enPermissions::pUpdateClients;
    }

    cout << "\nFind Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += clsUser::enPermissions::pFindClient;
    }

    cout << "\nTransactions? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += clsUser::enPermissions::pTranactions;
    }

    cout << "\nManage Users? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += clsUser::enPermissions::pManageUsers;
    }

    return Permissions;
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

void clsScreen::PrintUser(clsUser& User) {
	cout << "| " << setw(22) << left << User.fullname;
	cout << "| " << setw(20) << left << User.phone;
	cout << "| " << setw(17) << left << User.email;
	cout << "| " << setw(12) << left << User.UserName;
	cout << "| " << setw(12) << left << User.Password;
	cout << "| " << setw(10) << left << User.Permissions;
}

void clsScreen::_DrawScreenHeader(string Title, string SubTitle)
{
    clsDate Date;
    cout << "=================================================";
    cout << "\n  " << Title<<" | "; 
	clsDate::PrintTodayAndTime();
    if (SubTitle != "")
    {
        cout << "\n\t" << SubTitle;
    }
    cout << "\n=================================================\n";
}

