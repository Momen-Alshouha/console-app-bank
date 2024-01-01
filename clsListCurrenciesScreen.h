#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"

class clsListCurrenciesScreen : public clsScreen {
	
	static void _PrintCurrencyRecord(clsCurrency& Currency) {
		cout << "| " << left << setw(28) << Currency.country;
		cout << "| " << left << setw(28) << Currency.currencyName;
		cout << "| " << left << setw(28) << Currency.currencyCode;
		cout << "| " << left << setw(12) << Currency.rate;
	}

public:
	static void ListCurrencies() {
		_DrawScreenHeader("List Currencies Screen");
		vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		cout << "\n\t\t\t\t\tCurrencies List (" << vCurrencies.size() << ") Currency(s).";
		cout << "\n_______________________________________________________";
		cout << "_____________________________________________________\n" << endl;

		cout << "| " << left << setw(28) << "Country";
		cout << "| " << left << setw(28) << "Currency Name";
		cout << "| " << left << setw(28) << "Currency Code";
		cout << "| " << left << setw(12) << "Rate For Dollar";
		cout << "\n_______________________________________________________";
		cout << "_____________________________________________________\n" << endl;

		if (vCurrencies.size() == 0)
			cout << "\t\t\t\tNo Currencies Available In the System!";
		else

			for (clsCurrency& Currency : vCurrencies)
			{
				_PrintCurrencyRecord(Currency);
				cout << endl;
			}

		cout << "\n_______________________________________________________";
		cout << "_____________________________________________________\n" << endl;
	}


};