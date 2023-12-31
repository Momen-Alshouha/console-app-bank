#pragma once
#include "clsScreen.h"
#include "Global.h"

class clsTransfer : public clsScreen {

	static string _PrepareTransferLogRecord(clsClient& SourceClient,clsClient& DestinationClient, float Amount, string separator = "#//#") {

		return clsDate::GetTodayAndTime() + separator
			 + SourceClient.account_number + separator // from
			 + DestinationClient.account_number + separator // to
			 + to_string(Amount) + separator // amount 
			 + UserSession::getCurrentUser().UserName; // user
	}

	static void _AddTransferLogLineToFile(clsClient& SourceClient, clsClient& DestinationClient, float Amount, string separator = "#//#") {
		string LogLine = "";
		fstream LogTransferFile;
		LogTransferFile.open(LogTransferFilePath, ios::app);
		if (LogTransferFile.is_open())
		{
			LogLine = _PrepareTransferLogRecord(SourceClient, DestinationClient, Amount, separator);
			LogTransferFile << LogLine << endl;
			LogTransferFile.close();
		}
	}

	struct stLog;

	static stLog _ConvertLogLineToRecord(string LogLine) {

		vector<string> vlog = clsString::Split(LogLine,"#//#");
		
		return stLog(vlog[0], vlog[1], vlog[2], vlog[3], vlog[4]);

	}

	static vector<stLog> _LoadTransfersDataFromFile() {
		vector<stLog> vLogs; 
		stLog Log;
		fstream TransferLogs;
		TransferLogs.open(LogTransferFilePath, ios::in);
		string Line;
		if (TransferLogs.is_open())
		{
			while (getline(TransferLogs,Line))
			{
				Log = _ConvertLogLineToRecord(Line);
				vLogs.push_back(Log);
			}
			TransferLogs.close();
		}
		return vLogs;
	}

	static void _PrintTransferLogRecordLine(stLog Log)
	{
		cout << "| " << setw(35) << left << Log.DateAndTime;
		cout << "| " << setw(13) << left << Log.AccFrom;
		cout << "| " << setw(13) << left << Log.AccTo;
		cout << "| " << setw(13) << left << Log.Amounttransferred;
		cout << "| " << setw(13) << left << Log.UserPerformedTransfer;
	}

public:
	struct stLog
	{
		string DateAndTime, AccFrom, AccTo, Amounttransferred , UserPerformedTransfer;
		stLog(){};
		stLog(string dateAndTime,string accFrom,string accTo,string amountTransferred,string userPerformedTransfer) {
			DateAndTime = dateAndTime;
			AccFrom = accFrom;
			AccTo = accTo;
			Amounttransferred = amountTransferred;
			UserPerformedTransfer = userPerformedTransfer;
		}
	};

	static void Transfer() {
		float AmountToTransfer = 0;
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
		cout << "Client Transfered From Data\n";
		clsScreen::PrintShortlistedClient(TransferFromClient);
		cout << "Client Transfered To Data\n";
		clsScreen::PrintShortlistedClient(TransferToClient);
		cout << "\nThank You!\n";
		_AddTransferLogLineToFile(TransferFromClient, TransferToClient, AmountToTransfer);
	}


	static void _TransferLogScreen() {
		_DrawScreenHeader("Trasnfer Logs Screen");
		vector<stLog> vLogs = _LoadTransfersDataFromFile();

		cout << "\n\t\t\t\t\Transfer Logs List (" << vLogs.size() << ") Client(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "| " << left << setw(35) << "Date And Time";
		cout << "| " << left << setw(13) << "Client From";
		cout << "| " << left << setw(13) << "Client To";
		cout << "| " << left << setw(13) << "Amount";
		cout << "| " << left << setw(13) << "User";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vLogs.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (stLog& Log : vLogs)
			{
				_PrintTransferLogRecordLine(Log);
				cout << endl;
			}

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

};
