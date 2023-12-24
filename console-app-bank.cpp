
#include <iostream>
#include "clsDate.h"
#include "clsInputValidation.h"
#include "clsPeriod.h"
#include "clsString.h"
#include "clsUtil.h"
#include "clsClient.h"

using namespace std;

int main()
{
	clsClient Client = clsClient::Find("A101");
	Client.Print();
	cout << clsClient::IsClientExisits("123123") << endl;

}
