#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"

class clsFindCurrencyScreen : public clsScreen {

	static void _ShowResults(clsCurrency Currency) {
		if (Currency.IsEmpty())
		{
			cout << "currency not found\n";
		}
		else {
			_PrintCurrencyCard(Currency);
		}
	}

public:
	static void ShowFindCurrencyScreen() {
		
		_DrawScreenHeader("Find Currency Screen");
		cout << "How Do You Want To Search ? [1]By Currency Code [2]ByCountry : ";
		string option = to_string(clsInputValidate::ReadIntNumberBetween(1, 2));

		if (option=="1")
		{
			string code = clsInputValidate::ReadString("Enter Currency Code : ");
			clsCurrency Currency = clsCurrency::FindByCode(code);
			_ShowResults(Currency);
		}
		else if (option == "2") {
			string country = clsInputValidate::ReadString("Enter country : ");
			clsCurrency Currency = clsCurrency::FindByCountry(country);
			_ShowResults(Currency);
		}

		
	}
};