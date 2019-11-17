#include "ADMIN.h"


ADMIN::ADMIN(){
	name = "admin";
	pass = "123";
}
ADMIN::~ADMIN()
{
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
		Khach* temp = new NXB(username,password);
		member.push_back(temp);
	}
	else if (choice == 2) {
		cout << "== TAO TAI KHOAN TAC GIA == " << endl;
		cout << "Tao username: ";
		cin >> username;
		cout << "Tao password: ";
		cin >> password;
		Khach* temp = new TacGia(username, password);
		member.push_back(temp);
	}
	else if (choice == 3) {
		cout << "== TAO TAI KHOAN USER == " << endl;
		cout << "Tao username: ";
		cin >> username;
		cout << "Tao password: ";
		cin >> password;
		cout << "Tuoi: ";
		cin >> age;
		Khach* temp = new User(username, password,age);
		member.push_back(temp);
	}
}
int ADMIN::CheckUser(string in_username, string in_password,User& u) {
	list<Khach*>::iterator it;
	for (it = member.begin(); it != member.end(); it++) {
		if ((*it)->ClassName() == "User")
			if ((*it)->ten == in_username && (*it)->pass == in_password) {
				u.ten = (*it)->ten;
				u.pass = (*it)->pass;
				return 1;
			}
		return -1;
	}
}
int ADMIN::CheckNXB(string in_username, string in_password,NXB& nxb){
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
int ADMIN::CheckTacGia(string in_username, string in_password) {
	list<Khach*>::iterator it;
	for (it = member.begin(); it != member.end(); it++) {
		if ((*it)->ClassName() == "TacGia")
			if ((*it)->ten == in_username && (*it)->pass == in_password) {
				return 3;
			}
	}
	return -1;
}