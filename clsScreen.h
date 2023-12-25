#pragma once
#include <string>
#include <iostream>
#include "clsDate.h"
using namespace std;

class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string SubTitle = "");
	static void PrintSystemDate(clsDate Date);

};

