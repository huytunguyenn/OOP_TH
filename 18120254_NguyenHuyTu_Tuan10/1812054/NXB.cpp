#include "NXB.h"

NXB::NXB() {
}
NXB::NXB(string name, string password) {
	ten = name;
	pass = password;
}
string NXB::ClassName() {
	return "NXB";
}
NXB::NXB(NXB&other) {
	this->ten = other.ten;
	this->pass = other.pass;
	this->sach_nxb = other.sach_nxb;
}
int NXB::Check(string username, string password) {
	if (username == ten && password == pass)
		return 2;
	return -1;
}
void NXB::Init(ListSach& l) {
	// nếu sach_nxb đã tồn tại thì xóa
	if (!sach_nxb.listsach.empty())
		sach_nxb.~ListSach();
	if (sach_nxb.listsach.empty())
		return;
	list<Sach>::iterator it;
	for (it = this->sach_nxb.listsach.begin(); it != this->sach_nxb.listsach.end(); it++) {
		if (it->TACGIA == this->ten) {
			sach_nxb.listsach.push_back(*it);
		}
	}
}
void NXB::Delete(ListSach& l) {
	string name_delete;
	cout << "Nhap ten sach muon xoa: ";
	getline(cin, name_delete);
	// xóa sách khỏi sach_nxb
	sach_nxb.deleteName(name_delete);
	// xóa tên nxb sách trong list l
	l.deleteNXB(name_delete);
}