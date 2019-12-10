#pragma once
#include "User.h"
#include"Guest.h"
struct Hide {
	bool Author;
	bool NXB;
	bool Admin;
};
class Admin 
{
protected:
	string username;
	string password;
public:
	virtual string getObjName();
	void AddBook(ListBook &List_Book);
	string getUsername();
	string getPassword();
	virtual void DeleteBook(ListBook& List_Book,vector<Hide> &HiddenBook);
	Admin(string ,string);
	Admin();
	~Admin();
};

