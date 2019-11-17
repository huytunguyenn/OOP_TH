#include "User.h"

User::User() {
	age = 0;
}
User::User(string name,string password,int tuoi) {
	ten = name;
	pass = password;
	age = tuoi;
}
User::User(User& other) {
	this->ten = other.ten;
	this->pass = other.pass;
	this->age = other.age;
}
Khach* User::Clone() {
	return new User(*this);
}
string User::ClassName() {
	return "User";
}
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

bool User::Check(string Name, string Pass) {
	if (Name == ten && Pass == pass)
		return true;
	return false;
}