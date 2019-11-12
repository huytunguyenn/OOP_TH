#include "User.h"

void User::muaSach(ListSach& List_Book, MangHoaDon& List_Bill){
	List_Bill.inputListBill(List_Book);
	List_Bill.Output();
}
void User::updateBill(MangHoaDon& List_Bill){
	if (List_Bill.updateBill_Soluong() == true) {
		cout << "Cap nhat thanh cong!" << endl;
		cout <<endl<< "Don hang sau khi cap nhat" << endl;
		List_Bill.Output();
	}
	else
		cout << "Cap nhat that bai!" << endl;
}
User::User(){
	tuoi = 0;
	name = "abc";
	pass = "123";
}
bool User::Check(string Name, string Pass) {
	if (Name == name && Pass == pass)
		return true;
	return false;
}