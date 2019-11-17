#include "User.h"


void User::muaSach(ListSach& List_Book, MangHoaDon& List_Bill)
{
	List_Bill.inputListBill(List_Book);
	List_Bill.Output();
}

void User::updateBill(MangHoaDon& List_Bill)
{
	List_Bill.updateBill_Soluong();
	List_Bill.Output();
}

User::User()
{
	tuoi = 0;
	name = "ABC";
	pass = "123";
}

bool User::Check(string Name, string Pass) {
	if (Name == name && Pass == pass)
		return true;
	return false;
}