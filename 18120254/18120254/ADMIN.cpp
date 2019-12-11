#include "ADMIN.h"
#include "File.h"

ADMIN::ADMIN() {
	name = "admin";
	pass = "123";
	ReadListUser("account.txt",this->member);
}
ADMIN::~ADMIN(){
	this->member.clear();
}
int ADMIN::Check(string username, string password) {
	if (username == name && password == pass)
		return 4;
	return -1;
}
void ADMIN::AddMember() {
	int choice;
	do {
		system("cls");
		cout << "== CAC LOAI TAI KHOAN ==" << endl;
		cout << "1. NXB" << endl;
		cout << "2. Tac gia" << endl;
		cout << "3. User" << endl;
		cout << "Chon loai tai khoan muon them: ";
		cin >> choice;
	} while (!(choice > 0 && choice < 4));
	string username, password;
	int age;
	if (choice == 1) {
		cout << "== TAO TAI KHOAN NXB == " << endl;
		cout << "Tao username: ";
		cin >> username;
		cout << "Tao password: ";
		cin >> password;
		Khach* temp = new NXB(username, password);
		member.push_back(temp);
		WriteListUser("account.txt", temp);
	}
	else if (choice == 2) {
		cout << "== TAO TAI KHOAN TAC GIA == " << endl;
		cout << "Tao username: ";
		cin >> username;
		cout << "Tao password: ";
		cin >> password;
		Khach* temp = new TacGia(username, password);
		member.push_back(temp);
		WriteListUser("account.txt", temp);
	}
	else if (choice == 3) {
		cout << "== TAO TAI KHOAN USER == " << endl;
		cout << "Tao username: ";
		cin >> username;
		cout << "Tao password: ";
		cin >> password;
		cout << "Tuoi: ";
		cin >> age;
		Khach* temp = new User(username, password, age);
		member.push_back(temp);
		WriteListUser("account.txt", temp);
	}
}
int ADMIN::CheckUser(string in_username, string in_password, User& u) {
	list<Khach*>::iterator it;
	for (it = member.begin(); it != member.end(); it++) {
		if ((*it)->ClassName() == "User")
			if ((*it)->ten == in_username && (*it)->pass == in_password) {
				u.ten = (*it)->ten;
				u.pass = (*it)->pass;
				return 1;
			}
	}
	return -1;
}
int ADMIN::CheckNXB(string in_username, string in_password, NXB& nxb) {
	list<Khach*>::iterator it;
	for (it = member.begin(); it != member.end(); it++) {
		if ((*it)->ClassName() == "NXB")
			if ((*it)->ten == in_username && (*it)->pass == in_password) {
				nxb.ten = (*it)->ten;
				nxb.pass = (*it)->pass;
				return 2;
			}
	}
	return -1;
}
int ADMIN::CheckTacGia(string in_username, string in_password, TacGia& nxb) {
	list<Khach*>::iterator it;
	for (it = member.begin(); it != member.end(); it++) {
		if ((*it)->ClassName() == "TacGia")
			if ((*it)->ten == in_username && (*it)->pass == in_password) {
				nxb.ten = (*it)->ten;
				nxb.pass = (*it)->pass;
				return 3;
			}
	}
	return -1;
}
void ADMIN::OutputMember() {
	if (this->member.empty()) {
		cout << "Chua co tai khoan duoc tao" << endl;
		return;
	}
	else {
		list<Khach*>::iterator it;
		int y = 10;
		gotoxy(0, y); cout << "LOAI";
		gotoxy(10, y); cout << "TEN";
		gotoxy(20, y); cout << "PASS";
		for (it = member.begin(); it != member.end(); it++) {
			y++;
			gotoxy(0, y); cout << (*it)->ClassName();
			gotoxy(10, y); cout << (*it)->ten;
			gotoxy(20, y); cout << (*it)->pass << endl;
		}
	}
}
void ADMIN::DatKhoa(ListSach& l) {
	string name_sach;
	string lock_unit;
	cout << "Nhap ten sach: ";
	getline(cin, name_sach);
	list<Sach>::iterator it;
	for (it = l.listsach.begin();it!=l.listsach.end();it++) {
		if (it->TEN == name_sach) {
			cout << "Nhap ten nxb (hoac tac gia) bi cam: ";
			cin >> lock_unit;
			it->LOCK.push_back(lock_unit);
		}
	}
}