#pragma once
#include "clsScreen.h"

class clsCurrencyConverterScreen : public clsScreen {

	static float _ConvertToUSD(float amount,float rate) {
		return amount / rate;
	}


	static float _Convert(float &amount,float rate1From,float rate2To) {
		float result = _ConvertToUSD(amount, rate1From);
		result = result * rate2To;
		return result;
	}

public:
	static void ShowCurrencyConverterScreen() {
		float amount{};
		_DrawScreenHeader("Currency Converter");
		string CurrencyCodeFrom, CurrencyCodeTo{};
		bool isFound = true;
		do
		{
			if (!isFound)
			{
				cout << "Not Found Try Again!\n";
			}
			CurrencyCodeFrom = clsInputValidate::ReadString("Enter Currency To Convert From : ");
			clsCurrency CurrFrom = clsCurrency::FindByCode(CurrencyCodeFrom);
			isFound = clsCurrency::FindByCode(CurrencyCodeFrom).IsEmpty();
		} while (isFound);

		isFound = true;
		do
		{
			if (!isFound)
			{
				cout << "Not Found Try Again!\n";
			}
			CurrencyCodeTo = clsInputValidate::ReadString("Enter Currency To Convert From : ");
			isFound = clsCurrency::FindByCode(CurrencyCodeTo).IsEmpty();
		} while (isFound);

		clsCurrency CurrFrom = clsCurrency::FindByCode(CurrencyCodeFrom);
		clsCurrency CurrTo = clsCurrency::FindByCode(CurrencyCodeTo);
		cout << "Enter amount to convert : ";
		cin >> amount;
		cout << amount<<" "<<clsString::UpperAllString(CurrencyCodeFrom) << " = " << _Convert(amount, CurrFrom.rate, CurrTo.rate) <<" "<< clsString::UpperAllString(CurrencyCodeTo) << endl;;
	}
};