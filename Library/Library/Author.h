#pragma once
#include"Admin.h"
class Author :public Admin
{
	string AuthorName;
public:
	Author(string,string ,string);
	string getAuthorName();
	virtual string getObjName();
};

