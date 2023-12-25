#include "clsScreen.h"
#include "clsDate.h"


void clsScreen::PrintSystemDate(clsDate Date)
{
    Date.Print();
}

void clsScreen::_DrawScreenHeader(string Title, string SubTitle)
{
    clsDate Date;
    cout << "=================================================";
    cout << "\n\t  " << Title<<"     Date : "; 
    clsScreen::PrintSystemDate(Date);
    if (SubTitle != "")
    {
        cout << "\n\t" << SubTitle;
    }
    cout << "\n=================================================\n";
}

