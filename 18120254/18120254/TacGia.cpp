#include "TacGia.h"


TacGia::TacGia() {
}
TacGia::TacGia(string name, string password) {
	ten = name;
	pass = password;
}
string TacGia::ClassName() {
	return "TacGia";
}
TacGia::TacGia(TacGia&other) {
	this->ten = other.ten;
	this->pass = other.pass;
	this->sach_tacgia = other.sach_tacgia;
}
int TacGia::Check(string username, string password) {
	if (username == ten && password == pass)
		return 3;
	return -1;
}
void TacGia::Init(ListSach& l) {
	// nếu sach_tacgia đã tồn tại thì xóa
	if (!sach_tacgia.listsach.empty())
		sach_tacgia.listsach.clear();
	list<Sach>::iterator it;
	for (it = l.listsach.begin(); it != l.listsach.end(); it++) {
		if (it->TACGIA == this->ten) {
			sach_tacgia.listsach.push_back(*it);
		}
	}
}
void TacGia::Delete(ListSach& l) {
	string name_delete;
	cout << "Nhap ten sach muon xoa: ";
	getline(cin, name_delete);
	// xóa sách khỏi sach_tacgia
	sach_tacgia.deleteName(name_delete);
	// xóa tên tacgia sách trong list l
	l.deleteTacGia(name_delete);
}