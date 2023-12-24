#include "clsPerson.h"

clsPerson::clsPerson(string FirstName, string LastName, string Email, string Phone)
	: _FirstName(FirstName), _LastName(LastName), _Email(Email), _Phone(Phone) {}

string clsPerson::GetFirstName()
{
	return _FirstName;
}

void clsPerson::SetFirstName(string FirstName)
{
	_FirstName = FirstName;
}

string clsPerson::GetLastName()
{
	return _LastName;
}

void clsPerson::SetLastName(string LastName)
{
	_LastName = LastName;
}

string clsPerson::GetEmail()
{
	return _Email;
}

void clsPerson::SetEmail(string Email)
{
	_Email = Email;
}

string clsPerson::GetPhone()
{
	return _Phone;
}

void clsPerson::SetPhone(string Phone)
{
	_Phone = Phone;
}

bool clsPerson::GetMarkForDeletion()
{
	return _MarkForDeletion;
}

void clsPerson::SetMarkForDeletion(bool Mark)
{
	_MarkForDeletion = Mark;
}

string clsPerson::GetFullName()
{
	return _FirstName + " " + _LastName;
}
