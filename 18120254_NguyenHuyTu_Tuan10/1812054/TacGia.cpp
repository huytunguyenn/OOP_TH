#include "TacGia.h"



TacGia::TacGia(){
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
	if (sach_tacgia.pHead != NULL)
		sach_tacgia.~ListSach();
	if (l.pHead == NULL)
		return;
	for (Node* p = l.pHead; p != NULL; p = p->pNext) {
		if (p->data.TACGIA == ten) {
			Node*q = sach_tacgia.getNode(p->data);
			sach_tacgia.AddTail(q);
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