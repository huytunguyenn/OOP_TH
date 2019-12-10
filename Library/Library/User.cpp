#include "user.h"



void user::Muasach(ListBook& List_Book, ListBill& List_Bill)
{
	List_Bill.inputListBill(List_Book);
	List_Bill.outputListBill();
}

void user::updateBill(ListBill& List_Bill)
{
	List_Bill.updateBill_Soluong();
	List_Bill.outputListBill();
}
string user::getName()
{
	return this->name;
}
string user::getPass()
{
	return this->pass;
}
int user::getTuoi()
{
	return this->tuoi;
}
user::user(string name, string pass, int tuoi)
{
	this->name = name;
	this->pass = pass;
	this->tuoi = tuoi;
}



user::~user()
{
}
