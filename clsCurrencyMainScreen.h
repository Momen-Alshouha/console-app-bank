#pragma once
#include "clsScreen.h"
#include "clsMainMenu.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreenr.h"
#include "clsUpdateCurrencyScreen.h"

class clsCurrencyMainScreen :public clsScreen {
    
    enum enCurrencyMainMenuOption {
        enList = 1, enFind, enUpdateRate, enCurrencyCalculator, enMainMenuScreen
    };

    static int _ReadCurrencyMainMenuOption() {
        cout << "Enter Option [1-5] : ";
        return clsInputValidate::ReadIntNumberBetween(1, 5);
    }

    static void _List() {
        clsListCurrenciesScreen::ListCurrencies();
    }

    static void _Find() {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _UpdateRate() {
        clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
    }

    static void _CurrencyCalculator() {
        cout << "Calculator" << endl;

    }
    static void _BackToCurrencyMainMenu() {
        cout << "\nPress any key to back to main menu...\n";
        system("pause>0");
        ShowCurrencyMainMenu();
    }

    static void _PerfromCurrencyMainMenuOption(enCurrencyMainMenuOption Option) {
        system("cls");
        switch (Option)
        {
        case clsCurrencyMainScreen::enList:
            _List();
            break;
        case clsCurrencyMainScreen::enFind:
            _Find();
            break;
        case clsCurrencyMainScreen::enUpdateRate:
            _UpdateRate();
            break;
        case clsCurrencyMainScreen::enCurrencyCalculator:
            _CurrencyCalculator();
            break;
        case clsCurrencyMainScreen::enMainMenuScreen:
            //clsMainMenu::ShowMainMenu();
            break;
        default:
            break;
        }
        if (Option!=enMainMenuScreen)
        {
            _BackToCurrencyMainMenu();
        }
    }


public:
	static void ShowCurrencyMainMenu() {
        system("cls");
        _DrawScreenHeader("Main Screen");
        cout << "\t[1] List Currencies.\n";
        cout << "\t[2] Find Currency.\n";
        cout << "\t[3] Update Rate.\n";
        cout << "\t[4] Currency Calculator.\n";
        cout << "\t[5] Main Menu.\n";
        cout << "=================================================\n";

        _PerfromCurrencyMainMenuOption((enCurrencyMainMenuOption)_ReadCurrencyMainMenuOption());
	}
};