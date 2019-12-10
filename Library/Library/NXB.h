#pragma once
#include"Admin.h"
class NXB :public Admin
{
	string NXBname;
public:
	NXB(string , string,string);
	virtual string getObjName();
	string getNXBname();
};

