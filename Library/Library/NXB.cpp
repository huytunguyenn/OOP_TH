#include "NXB.h"

NXB::NXB(string username, string password, string NXBname)
{
	this->username = username;
	this->password = password;
	this->NXBname = NXBname;
}

string NXB::getObjName()
{
	return "NXB";
}

string NXB::getNXBname()
{
	return this->NXBname;
}
