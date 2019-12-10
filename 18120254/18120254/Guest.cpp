#include "Guest.h"


void Guest::TimSach(ListSach& l) {
	Sach temp = l.TimSach();
	if (!temp.TEN.empty())
		cout << temp << endl;
	else
		cout << "Khong tim thay sach" << endl;
}

void Guest::Signup(ADMIN& admin) {
	int choice;
	do {
		system("cls");
		cout << "== CAC LOAI TAI KHOAN ==" << endl;
		cout << "1. NXB" << endl;
		cout << "2. Tac gia" << endl;
		cout << "3. User" << endl;
		cout << "4. Quay lai" << endl;
		cout << "Chon loai tai khoan muon them: ";
		cin >> choice;
		if (!(choice > 0 && choice < 5)) {
			cout << "Vui long nhap lai";
			system("pause");
		}
	} while (!(choice > 0 && choice < 5));
	string username, password;
	int age;
	if (choice == 1) {
		cout << "== TAO TAI KHOAN NXB == " << endl;
		cout << "Tao username: ";
		cin >> username;
		cout << "Tao password: ";
		cin >> password;
		Khach* temp = new NXB(username, password);
		admin.member.push_back(temp);
		WriteListUser("account.txt",temp);
	}
	else if (choice == 2) {
		cout << "== TAO TAI KHOAN TAC GIA == " << endl;
		cout << "Tao username: ";
		cin >> username;
		cout << "Tao password: ";
		cin >> password;
		Khach* temp = new TacGia(username, password);
		admin.member.push_back(temp);
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
		admin.member.push_back(temp);
		WriteListUser("account.txt", temp);
	}
	cout << "Them tai khoan thanh cong" << endl;
	system("pause");
}
