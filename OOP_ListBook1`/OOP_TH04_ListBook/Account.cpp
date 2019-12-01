#include "Account.h"



Account::Account()
{
}


Account::~Account()
{
}

void Account::setUsernameAccount(string ten)
{
	mTen = ten;
}

void Account::setPassAccount(string pass)
{
	mPass = pass;
}

string Account::getUsernameAccount()
{
	return string(mTen);
}

string Account::getPassAccount()
{
	return string(mPass);
}