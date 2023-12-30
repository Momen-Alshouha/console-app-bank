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
	User.firstname = clsInputValidate::ReadString("\nEnter First Name : ");
	User.lastname = clsInputValidate::ReadString("\nEnter Last Name : ");
	User.email = clsInputValidate::ReadString("\nEnter Email : ");
	User.phone = clsInputValidate::ReadString("\nEnter Phone Number : ");
	User.Password= clsInputValidate::ReadString("\nEnter Password : ");
	cout << "\nEnter Permission: ";
	User.Permissions= _ReadPermissionsToSet();
}

int clsScreen::_ReadPermissionsToSet() {
    
    int Permissions = 0;
    string Answer = "n";

    cout << "\nDo you want to give full access? y/n? ";
    cin >> Answer;
    if (tolower(Answer[0]) == 'y')
    {
        return -1;
    }

    cout << "\nDo you want to give access to : \n ";

    cout << "\nShow Client List? y/n? ";
    cin >> Answer;
    if (tolower(Answer[0]) == 'y')
    {


        Permissions += clsUser::enPermissions::pListClients;
    }

    cout << "\nAdd New Client? y/n? ";
    cin >>ws>> Answer;
    if (tolower(Answer[0]) == 'y')
    {
        Permissions += clsUser::enPermissions::pAddNewClient;
    }

    cout << "\nDelete Client? y/n? ";
    cin >> Answer;
    if (tolower(Answer[0]) == 'y')
    {
        Permissions += clsUser::enPermissions::pDeleteClient;
    }

    cout << "\nUpdate Client? y/n? ";
    cin >> Answer;
    if (tolower(Answer[0]) == 'y')
    {
        Permissions += clsUser::enPermissions::pUpdateClients;
    }

    cout << "\nFind Client? y/n? ";
    cin >> Answer;
    if (tolower(Answer[0]) == 'y')
    {
        Permissions += clsUser::enPermissions::pFindClient;
    }

    cout << "\nTransactions? y/n? ";
    cin >> Answer;
    if (tolower(Answer[0]) == 'y')
    {
        Permissions += clsUser::enPermissions::pTranactions;
    }

    cout << "\nManage Users? y/n? ";
    cin >> Answer;
    if (tolower(Answer[0]) == 'y')
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
	cout << "\nPinCode    : " << client.pin_code;
	cout << "\nBalance     : " << client.balance;
	cout << "\n___________________\n";
}

void clsScreen::PrintUserCard(clsUser& User) {

    cout << "\nUser Card:";
    cout << "\n___________________";
    cout << "\nFull Name   : " << User.fullname;
    cout << "\nPhone       : " << User.phone;
    cout << "\nEmail       : " << User.email;
    cout << "\nUsername    : " << User.UserName;
    cout << "\nPassword    : " << User.Password;
    cout << "\nPermissions : " << User.Permissions;
    cout << "\n___________________\n";
}

void clsScreen::PrintUserRecord(clsUser& User) {
    cout << "| " << left << setw(22) << User.fullname;
    cout << "| " << left << setw(20) << User.phone;
    cout << "| " << left << setw(17) << User.email;
    cout << "| " << left << setw(12) << User.UserName;
    cout << "| " << left << setw(12) << User.Password;
    cout << "| " << left << setw(12) << User.Permissions;
}

void clsScreen::_DrawScreenHeader(string Title, string SubTitle)
{
    clsDate Date;
    cout << "=================================================";
    if (!UserSession::getCurrentUser().IsEmpty())
    {
        cout << endl<<"  Welcome " << UserSession::getCurrentUser().UserName << endl;
    }
    cout << "\n  " << Title<<" | "; 
	clsDate::PrintTodayAndTime();
    if (SubTitle != "")
    {
        cout << "\n\t" << SubTitle;
    }
    
    cout << "\n=================================================\n";
}

