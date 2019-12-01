#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include<iostream>
#include<string>
using namespace std;

class Account
{
protected:
	string mTen;//username
	string mPass;//mật khẩu
	string nameclass;
public:
	Account();
	~Account();
	void setUsernameAccount(string ten);
	void setPassAccount(string pass);
	string getUsernameAccount();
	string getPassAccount();


};

#endif