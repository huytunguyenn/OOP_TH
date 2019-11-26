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
	if (sach_nxb.pHead != NULL)
		sach_nxb.~ListSach();
	if (l.pHead == NULL)
		return;
	for (Node* p = l.pHead; p != NULL; p = p->pNext) {
		if (p->data.NXB == ten) {
			Node*q = sach_nxb.getNode(p->data);
			sach_nxb.AddTail(q);
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