#pragma once
#include"guest.h"
class user :public guest
{
	string name;
	string pass;
	int tuoi;
public:
	void Muasach(ListBook& List_Book, ListBill& List_Bill);
	void updateBill(ListBill& List_Bill);
	string getName();
	string getPass();
	int getTuoi();
	user(string,string,int);
	~user();
};

