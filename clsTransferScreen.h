#pragma once
#include "clsScreen.h"

class clsTransferScreen : public clsScreen {

public:

	static void Transfer() {
		double AmountToTransfer = 0;
		_DrawScreenHeader("Transfer Screen");
		
		string AccNumFrom = clsInputValidate::ReadString("\nEnter Account Number To Transfer From : ");

		while (!clsClient::IsClientExisits(AccNumFrom))
		{
			AccNumFrom = clsInputValidate::ReadString("\nClient does not exist!\nEnter Account Number To Transfer From :\n");
		}
		
		string AccNumTo = clsInputValidate::ReadString("\nEnter Account Number To Transfer To : \n");

		while (!clsClient::IsClientExisits(AccNumTo))
		{
			AccNumTo = clsInputValidate::ReadString("\nClient dows not exist!\nEnter Account Number To Transfer To : \n");
		}

		clsClient TransferFromClient = clsClient::Find(AccNumFrom);
		clsClient TransferToClient = clsClient::Find(AccNumTo);
		system("cls");
		_DrawScreenHeader("Transfer Screen");
		cout << "\nClient To Transfer From Data: ";
		clsScreen::PrintShortlistedClient(TransferFromClient);
		cout << "\nClient To Transfer To Data: ";
		clsScreen::PrintShortlistedClient(TransferToClient);
		cout << "-------------------------------\n";
		cout << "\nBalance is "<<TransferFromClient.balance<<" Enter Amount To Transfer : \n";
		AmountToTransfer = clsInputValidate::ReadFloatNumberBetween(1, TransferFromClient.balance);
		TransferFromClient.Transfer(AmountToTransfer, TransferToClient);
		system("cls");
		_DrawScreenHeader("Transfer Screen");
		cout << "\nAmount Transfered Successfully\n";
		cout << "Client To Transfered From Data\n";
		clsScreen::PrintShortlistedClient(TransferFromClient);
		cout << "Client Transfered To Data\n";
		clsScreen::PrintShortlistedClient(TransferToClient);
		cout << "\nThank You!\n";
	}
};
