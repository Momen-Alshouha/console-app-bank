#pragma once
#include "clsScreen.h"

class clsUpdateCurrencyScreen : public clsScreen {

public:
	static void ShowUpdateCurrencyScreen() {
		float NewRate = 0;
		_DrawScreenHeader("Update Rate Screen");
		string CurrencyCode = clsInputValidate::ReadString("Enter Currency Code : ");
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		while (Currency.IsEmpty())
		{
			CurrencyCode = clsInputValidate::ReadString("Enter Currency Code : ");
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		}
		_PrintCurrencyCard(Currency);
		cout << "Enter New Rate : ";
		cin >> NewRate;
		Currency.UpdateRate(NewRate);
		system("cls");
		cout << "\n\nRate updated successfully!\n";
		_PrintCurrencyCard(Currency);
	}


};