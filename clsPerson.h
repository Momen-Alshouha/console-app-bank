#pragma once
#include <iostream>
using namespace std;

class clsPerson
{
	string _FirstName, _LastName, _Email, _Phone;
	bool _MarkForDeletion = false;

public:
	
	clsPerson(string FirstName,string LastName,string Email,string Phone);

	string GetFirstName();
	void SetFirstName(string FirstName);

	string GetLastName();
	void SetLastName(string LastName);

	string GetEmail();
	void SetEmail(string Email);

	string GetPhone();
	void SetPhone(string Phone);

	bool GetMarkForDeletion();
	void SetMarkForDeletion(bool Mark);

	string GetFullName();

	// properities
	__declspec(property (get = GetFirstName, put = SetFirstName)) string firstname;
	__declspec(property (get = GetLastName, put = SetLastName)) string lastname;
	__declspec(property (get = GetFullName)) string fullname; // read only
	__declspec(property (get = GetEmail, put = SetEmail)) string email;
	__declspec(property (get = GetPhone, put = SetPhone)) string phone;
	__declspec(property (get = GetMarkForDeletion, put = SetMarkForDeletion)) bool markForDeletion;

};

