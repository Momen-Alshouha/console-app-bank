#pragma once
#include "clsScreen.h"

struct stLoginLog {
	string DateAndTime, Username, Fullname;
};

class clsLoginLogs :public clsScreen {
	
	stLoginLog Log;
	
	static stLoginLog _ConvertDataLogFromLineToRecord(string LogLine) {
		stLoginLog Log;
		vector<string> vLog = clsString::Split(LogLine, "#//#");
		Log.DateAndTime = vLog[0];
		Log.Username = vLog[1];
		Log.Fullname= vLog[2];
		return Log;
	}

	static vector<stLoginLog> _LoadDataFromLogFileToVector() {
		fstream LogFile;
		string LogLine="";
		stLoginLog Log;
		vector<stLoginLog> vLogs;
		LogFile.open(LogFilePath, ios::in);
		if (LogFile.is_open())
		{
			while (getline(LogFile,LogLine))
			{
				Log = _ConvertDataLogFromLineToRecord(LogLine);
				vLogs.push_back(Log);
			}
			LogFile.close();
		}
		return vLogs;
	}

	static void _PrintLogRecordLine(stLoginLog Log) {
		cout << "| " << setw(35) << left << Log.DateAndTime;
		cout << "| " << setw(15) << left << Log.Username;
		cout << "| " << setw(20) << left << Log.Fullname;
	}

public:
	static void ShowLoginLogs() {
		vector<stLoginLog> vLogs = _LoadDataFromLogFileToVector();
		_DrawScreenHeader("Logs List");
		cout << "\n\t\t\t\t\Logs List (" << vLogs.size() << ") Client(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << "| " << left << setw(35) << "Date And Time";
		cout << "| " << left << setw(15) << "Username";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vLogs.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (stLoginLog& Log : vLogs)
			{
				_PrintLogRecordLine(Log);
				cout << endl;
			}

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};