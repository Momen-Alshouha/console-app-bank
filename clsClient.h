#pragma once
#include <vector>
#include "clsPerson.h"
#include "clsInputValidation.h"

class clsClient : public clsPerson
{
	enum enMode { EmptyMode = 0, UpdateMode ,AddMode };
	const static string ClientFileName;

	string _AccountNumber, _PinCode;
	float _Balance;
	enMode _Mode=EmptyMode;
	
	static string _ConvertClientObjectToLine(clsClient Client,string Line,string Delimeter);

	static clsClient _ConvertClientLineToClientObject(string Line, string Delimeter );

	static clsClient _GetEmptyClientObject();

	static void _SaveClienstDataToFile(vector<clsClient> &vClients);

	static vector<clsClient> _LoadClientsDataFromFile();

	void _AddClientDataToFile(string ClientLine);

	void _Update();

	void _Add();

	void _MarkClientForDelete(vector<clsClient>& vClients, string AccountNumber);

	static void _MarkAllClientsForDelete(vector<clsClient>& vClients);

	static float _GetTotalBalances(vector<clsClient> vClients);

public:
	
	enum enSaveResult
	{
		svSuccess = 0, svFailed, svClientExist
	};

	clsClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber,string _PinCode, float Balance);
	string GetAccountNumber();
	
	string GetPinCode();
	void SetPinCode(string PinCode);

	float GetBalance();
	void SetBalance(float Balance);

	// properities
	__declspec(property(get = GetAccountNumber)) string account_number; // read only
	__declspec(property(get = GetBalance, put=SetBalance)) float balance; 
	__declspec(property(get = GetPinCode, put = SetPinCode)) string pin_code; 

	static clsClient Find(string AccountNumber);

	static clsClient Find(string AccountNumber,string PinCode);

	bool IsEmplty();

	static bool IsClientExisits(string AccountNumber);

	enSaveResult Save();

	static clsClient GetAddNewClientObject(string AccountNumber);

	bool Delete();

	static vector<clsClient> GetClientsList();

	static double GetTotalBalances();

	static bool DeleteAll();

	
};
